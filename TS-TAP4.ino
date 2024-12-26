/**
 * @file TS-TAP4.ino
 * @brief Arduino tap drum machine with looper
 * @author Turi Scandurra
 * @version 1.0.0
 * @date 2022.05.03
 */
/*
 ____________  __   ______  ___  __________ ______
/_  __/ __ \ \/ /  / __/\ \/ / |/ /_  __/ // / __/
 / / / /_/ /\  /  _\ \   \  /    / / / / _  /\ \  
/_/  \____/ /_/  /___/   /_/_/|_/ /_/ /_//_/___/  

TS-TAP4 - Arduino tap drum machine with looper
By Turi Scandurra - https://turiscandurra.com/circuits

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

/**
 * @def NUM_SAMPLES
 * @brief Number of sound samples
 */
#define NUM_SAMPLES 4

/**
 * @def NUM_SENSORS
 * @brief Number of capacitive sensors
 */
#define NUM_SENSORS 5

/**
 * @def THRESHOLD
 * @brief Threshold value for capacitive sensor readings
 * @note Adjust to fit the wiring and surface area of your conductive inputs
 */
#define THRESHOLD 512

/**
 * @def MIN_MSEC_DELAY
 * @brief Minimum time in milliseconds between retriggers
 */
#define MIN_MSEC_DELAY 100

/**
 * @def MAX_TAPS
 * @brief Maximum number of taps that can be recorded
 */
#define MAX_TAPS 32

// Pin assignment
const uint8_t sendPin = 2;
const uint8_t touchPins[NUM_SAMPLES] = { 3, 4, 5, 6 };
const uint8_t ledPins[NUM_SAMPLES] = { 8, 9, 10, 12 };
const uint8_t recTouchPin = 7;
const uint8_t recLedPin = 13;
// Speaker pin is 11, defined in PCM.c

// Sensor and recording variables
bool pressed[NUM_SENSORS];
uint8_t tapIndex;
bool recording;
uint32_t recStart;
uint32_t loopStart;
uint32_t loopLength;
uint8_t tapsNotes[MAX_TAPS]; // This is where we store tap data. Tap notes here,
uint32_t tapsTimestamps[MAX_TAPS]; // tap timestamps here,
bool tapsPlayed[MAX_TAPS]; // and tap played status here, used when replaying the loop.

// Capacitive sensors
CapacitiveSensor capSensors[NUM_SENSORS] = {
    CapacitiveSensor(sendPin, touchPins[0]),
    CapacitiveSensor(sendPin, touchPins[1]),
    CapacitiveSensor(sendPin, touchPins[2]),
    CapacitiveSensor(sendPin, touchPins[3]),
    CapacitiveSensor(sendPin, recTouchPin)
};
const uint8_t recSensorIndex = 4;   // Derive index from the position of the Rec sensor on the above list.
                                    // It's used to access sensors iteratively.

// Timers for turning off LEDs and preventing continuous sensor triggers
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

/**
 * @brief Setup function
 */
void setup() {
    // Initialize LED pins as outputs
    for (int i = 0; i < NUM_SAMPLES; ++i) {
        pinMode(ledPins[i], OUTPUT);
    }
    pinMode(recLedPin, OUTPUT);
}

/**
 * @brief Start recording function
 */
void startRecording() {
    digitalWrite(recLedPin, HIGH);
    recording = true;
    recStart = millis();
    tapIndex = 0;
    memset(tapsNotes, 0, MAX_TAPS);
    memset(tapsTimestamps, 0, MAX_TAPS);
    memset(tapsPlayed, false, MAX_TAPS);
}

/**
 * @brief Stop recording function
 */
void stopRecording() {
    digitalWrite(recLedPin, LOW);
    recording = false;
    loopLength = millis() - recStart;
    loopStart = 0;
}

/**
 * @brief Add a tap to the recording
 * @param n Tap index
 * @param timestamp Timestamp of the tap
 */
void addTap(uint8_t n, uint32_t timestamp) {
    if (tapIndex < MAX_TAPS) {
        tapsNotes[tapIndex] = n;
        tapsTimestamps[tapIndex] = timestamp;
        tapIndex++;
    }
}

/**
 * @brief Handle sensor press event
 * @param n Sensor index
 */
void onPress(uint8_t n) {
    switch (n) {
        case recSensorIndex:
            if (recording) {
                stopRecording();
            }
            break;
        default:
            playSample(n);
            if (!recording) {
                startRecording();
            }
            addTap(n, millis() - recStart);
    }
}

/**
 * @brief Play a sound sample
 * @param n Sample index
 */
void playSample(uint8_t n) {
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

/**
 * @brief Check if a sensor is pressed
 * @param n Sensor index
 */
void checkPressed(uint8_t n) {
    if (capSensors[n].capacitiveSensor(32) < THRESHOLD) {
        pressed[n] = false;
        return;
    }
    if (!pressed[n] && delays[n]->isExpired()) {
        onPress(n);
        pressed[n] = true;
    }
}

/**
 * @brief Main loop function
 */
void loop() {
    uint32_t now = millis();

    // Check sensor states and play samples
    for (int i = 0; i < NUM_SAMPLES; ++i) {
        if (delays[i]->isExpired()) {
            digitalWrite(ledPins[i], LOW);
        }
        checkPressed(i);
    }
    checkPressed(recSensorIndex);

    // Play recorded loop
    if (!recording) {
        if (now - loopStart > loopLength) { // Loop start or restart
            loopStart = now;
            memset(tapsPlayed, false, MAX_TAPS);
        }
        for (int i = 0; i < tapIndex; ++i) {
            if (now - loopStart >= tapsTimestamps[i] && !tapsPlayed[i]) {
                playSample(tapsNotes[i]);
                tapsPlayed[i] = true;
            }
        }
    }

    // Add a small delay to prevent excessive CPU usage
    delay(2);
}

