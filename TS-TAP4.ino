/*
 ____________  __   ______  ___  __________ ______
/_  __/ __ \ \/ /  / __/\ \/ / |/ /_  __/ // / __/
 / / / /_/ /\  /  _\ \   \  /    / / / / _  /\ \  
/_/  \____/ /_/  /___/   /_/_/|_/ /_/ /_//_/___/  

TS-TAP4 - Arduino tap drum machine with looper
By Turi Scandurra - https://turiscandurra.com/circuits
v1.0.0 - 2022.05.03

Written for Arduino Nano or Arduino Uno.

The sound samples are unsigned 8 bit 8000 Hz WAV files converted to header files using wav2c,
a tool which can be compiled from the sources available at https://github.com/jelly/arduinoaudiobox/tree/master/tools .
After the conversion, you need to manually edit the header files and add the PROGMEM directive
like in the samples provided.

*/
#include <AsyncDelay.h> // from https://github.com/stevemarple/AsyncDelay
#include <CapacitiveSensor.h> // from https://github.com/PaulStoffregen/CapacitiveSensor
#include "PCM.h" // from https://github.com/jelly/arduinoaudiobox. You'll also need PCM.c

#include "samples/kick.h"
#include "samples/snare.h"
#include "samples/hihat.h"
#include "samples/clap.h"

#define NUM_SAMPLES 4
#define NUM_SENSORS 5
#define THRESHOLD 512 // Adjust to fit the wiring and surface area of your conductive inputs
#define MIN_MSEC_DELAY 100 // Minimum time in milliseconds between retriggers
#define MAX_TAPS 32

// Pin assignment
const uint8_t sendPin = 2;
const uint8_t touchPins[NUM_SAMPLES] = { 3, 4, 5, 6 };
const uint8_t ledPins[NUM_SAMPLES] = { 8, 9, 10, 12 };
const uint8_t recTouchPin = 7;
const uint8_t recLedPin = 13;
// Speaker pin is 11, defined in PCM.c

bool pressed[NUM_SENSORS]; // We're storing here the pressed status of each sensor
uint8_t tapIndex; // A counter that keeps track of how many taps have been recorded so far
bool recording = false;
uint32_t recStart;
uint32_t loopStart;
uint32_t loopLength;
uint8_t tapsNotes [MAX_TAPS]; // This is where we store tap data. Tap notes here,
uint32_t tapsTimestamps [MAX_TAPS]; // tap timestamps here,
bool tapsPlayed [MAX_TAPS]; // and tap played status here, used when replaying the loop.

CapacitiveSensor capSensors[NUM_SENSORS] = {
    CapacitiveSensor(sendPin, touchPins[0]),
    CapacitiveSensor(sendPin, touchPins[1]),
    CapacitiveSensor(sendPin, touchPins[2]),
    CapacitiveSensor(sendPin, touchPins[3]),
    CapacitiveSensor(sendPin, recTouchPin)
};
const uint8_t recSensorIndex = 4;   // Derive index from the position of the Rec sensor on the above list.
                                    // It's used to access sensors iteratively.

// Setup the timers. They're used to turn off LEDs and to make sure a sensor does not get continuosly triggered
AsyncDelay delay0;
AsyncDelay delay1;
AsyncDelay delay2;
AsyncDelay delay3;
AsyncDelay delay4;

AsyncDelay* delays[NUM_SENSORS] = {
    &delay0,
    &delay1,
    &delay2,
    &delay3,
    &delay4
};

void setup() {
    pinMode(ledPins[0], OUTPUT);
    pinMode(ledPins[1], OUTPUT);
    pinMode(ledPins[2], OUTPUT);
    pinMode(ledPins[3], OUTPUT);
    pinMode(recLedPin, OUTPUT);
}

void startRecording(){
    digitalWrite(recLedPin, HIGH);
    recording = true;
    recStart = millis();
    tapIndex = 0;
    memset(tapsNotes, 0, MAX_TAPS);
    memset(tapsTimestamps, 0, MAX_TAPS);
    memset(tapsPlayed, false, MAX_TAPS); // TODO redundant?
}

void stopRecording(){
    digitalWrite(recLedPin, LOW);
    recording = false;
    loopLength = millis() - recStart;
    loopStart = 0; // TODO redundant?
}

void addTap(uint8_t n, uint32_t timestamp){
    if(tapIndex < MAX_TAPS){
        tapsNotes[tapIndex] = n;
        tapsTimestamps[tapIndex] = timestamp;
        tapIndex++;
    }
}

void onPress(uint8_t n){
    switch(n){
        case recSensorIndex:
            if(recording){
                stopRecording();
            }
            break;
        default:
            playSample(n);
            if(!recording){
                startRecording();
            }
            addTap(n, millis() - recStart);
    }
}

void playSample(uint8_t n){
    delays[n]->start(MIN_MSEC_DELAY, AsyncDelay::MILLIS); // Trigger a delay so the LED will be turned off when it's time
    digitalWrite(ledPins[n], HIGH); // Turn LED on
    switch(n){
        case 0:
            startPlayback(kick_data, kick_length); // These variable names must match what's in the samples' header files
            break;
        case 1:
            startPlayback(snare_data, snare_length);
            break;
        case 2:
            startPlayback(hihat_data, hihat_length);
            break;
        case 3:
            startPlayback(clap_data, clap_length);
            break;
    }
}

void checkPressed(uint8_t n){
    if(capSensors[n].capacitiveSensor(32) < THRESHOLD){
        pressed[n] = false;
        return;
    }
    if(!pressed[n] && delays[n]->isExpired()) { // The sensor is pressed and there's no active delay on it,
        onPress(n); // let's trigger the callback function
        pressed[n] = true;
    }
}

void loop() {
    uint32_t now = millis();

    for (int i = 0; i < NUM_SAMPLES; ++i) {
        if(delays[i]->isExpired()) {
            // Turn off samples LEDs
            digitalWrite(ledPins[i], LOW);
        }
        checkPressed(i);
    }
    checkPressed(recSensorIndex);

    if(!recording){
        if(now - loopStart > loopLength){ // Loop start or restart
            loopStart = now;
            memset(tapsPlayed, false, MAX_TAPS);
        }
        for (int i = 0; i < tapIndex; ++i) {
            if(now - loopStart >= tapsTimestamps[i] && !tapsPlayed[i]){
                playSample(tapsNotes[i]);
                tapsPlayed[i] = true;
            }
        }
    }

    delay(2); // TODO this delay is arbitrary and could be redundant
}