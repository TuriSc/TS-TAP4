// kick sound made by wav2c

const int kick_sampleRate=8000;
const int kick_length=2480;

const unsigned char kick_data[] PROGMEM ={128, 
128, 128, 128, 128, 128, 127, 161, 185, 186, 179, 157, 132, 100, 71, 41, 18, 3, 0, 0, 5, 
21, 41, 66, 93, 121, 148, 173, 196, 213, 227, 237, 242, 242, 236, 228, 215, 199, 180, 159, 138, 
116, 93, 72, 52, 34, 18, 4, 0, 0, 0, 0, 0, 0, 0, 0, 9, 21, 35, 51, 67, 
85, 104, 122, 141, 160, 180, 197, 216, 233, 250, 255, 254, 255, 255, 255, 255, 255, 255, 255, 254, 
254, 255, 255, 255, 255, 255, 255, 255, 246, 232, 218, 205, 192, 179, 169, 157, 147, 138, 129, 120, 
113, 106, 99, 92, 85, 80, 73, 67, 61, 54, 48, 42, 36, 30, 24, 18, 12, 6, 1, 0, 
0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 3, 9, 15, 23, 29, 36, 43, 51, 59, 
66, 74, 82, 91, 98, 106, 113, 121, 129, 137, 145, 152, 159, 166, 174, 181, 188, 195, 201, 207, 
214, 220, 226, 232, 237, 241, 246, 250, 254, 254, 254, 255, 255, 255, 254, 255, 255, 255, 255, 255, 
255, 255, 255, 255, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
255, 255, 255, 255, 255, 255, 255, 254, 255, 252, 247, 242, 237, 231, 227, 220, 215, 209, 203, 196, 
190, 185, 178, 171, 164, 158, 151, 145, 137, 130, 124, 118, 111, 104, 97, 91, 84, 79, 73, 67, 
60, 55, 49, 44, 39, 33, 28, 22, 19, 14, 10, 7, 2, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 
0, 0, 0, 0, 4, 7, 11, 14, 19, 23, 26, 31, 35, 40, 45, 49, 54, 58, 64, 69, 
73, 79, 84, 90, 93, 99, 104, 109, 114, 119, 125, 130, 135, 139, 143, 148, 153, 158, 162, 166, 
170, 174, 179, 183, 186, 191, 194, 198, 201, 204, 209, 211, 215, 217, 221, 224, 227, 230, 232, 235, 
237, 240, 241, 244, 247, 248, 250, 252, 253, 254, 255, 255, 255, 255, 255, 254, 255, 255, 255, 255, 
254, 255, 255, 255, 255, 253, 251, 250, 248, 246, 243, 241, 237, 235, 233, 229, 226, 222, 219, 214, 
211, 207, 202, 198, 194, 189, 184, 180, 175, 169, 165, 160, 154, 149, 143, 139, 133, 128, 123, 117, 
111, 106, 100, 95, 90, 84, 78, 74, 69, 63, 58, 53, 48, 43, 39, 34, 29, 25, 22, 18, 
13, 9, 7, 3, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 2, 5, 8, 12, 15, 19, 23, 28, 
32, 37, 41, 46, 50, 55, 59, 64, 69, 75, 80, 84, 90, 95, 100, 105, 110, 115, 120, 125, 
130, 135, 139, 144, 149, 154, 158, 162, 168, 171, 175, 179, 183, 186, 190, 194, 197, 200, 203, 207, 
209, 212, 215, 218, 219, 222, 224, 226, 228, 230, 231, 234, 235, 236, 236, 239, 239, 240, 241, 241, 
241, 242, 242, 242, 242, 240, 241, 240, 239, 238, 238, 236, 235, 233, 231, 230, 227, 225, 222, 219, 
216, 214, 212, 209, 205, 202, 199, 195, 193, 188, 184, 181, 177, 173, 170, 165, 161, 157, 154, 149, 
145, 141, 136, 133, 129, 124, 121, 116, 112, 108, 105, 100, 97, 93, 89, 86, 82, 79, 76, 72, 
69, 66, 62, 59, 57, 55, 51, 49, 47, 45, 43, 41, 40, 38, 37, 35, 34, 33, 32, 32, 
31, 30, 30, 30, 29, 30, 31, 32, 32, 33, 33, 34, 35, 37, 38, 39, 42, 43, 45, 47, 
48, 51, 54, 56, 58, 61, 64, 66, 69, 72, 75, 78, 81, 83, 88, 90, 94, 96, 100, 103, 
106, 110, 112, 117, 119, 123, 126, 129, 132, 135, 138, 142, 145, 148, 151, 154, 156, 160, 162, 165, 
167, 170, 172, 175, 177, 179, 182, 183, 186, 188, 188, 191, 193, 193, 196, 196, 198, 199, 200, 201, 
203, 203, 203, 204, 205, 206, 206, 206, 206, 206, 206, 206, 205, 206, 205, 203, 203, 202, 201, 201, 
199, 199, 196, 196, 194, 192, 191, 189, 187, 184, 183, 181, 179, 176, 174, 172, 169, 166, 164, 161, 
159, 156, 153, 150, 147, 144, 141, 139, 136, 133, 130, 128, 125, 121, 119, 116, 113, 110, 108, 105, 
103, 99, 98, 94, 93, 90, 88, 86, 83, 81, 80, 77, 76, 74, 72, 70, 70, 68, 66, 66, 
64, 64, 62, 62, 61, 61, 60, 60, 60, 59, 58, 59, 61, 60, 60, 61, 61, 62, 63, 64, 
65, 66, 67, 68, 69, 71, 72, 74, 75, 76, 78, 81, 82, 84, 85, 88, 90, 92, 94, 96, 
97, 99, 102, 105, 107, 109, 112, 113, 116, 118, 120, 123, 125, 127, 129, 131, 133, 136, 138, 140, 
141, 144, 146, 148, 150, 151, 153, 155, 157, 158, 160, 161, 162, 163, 165, 167, 168, 170, 171, 171, 
173, 174, 175, 175, 176, 176, 176, 178, 178, 178, 179, 180, 179, 179, 179, 179, 179, 179, 179, 179, 
179, 178, 178, 177, 176, 176, 174, 174, 172, 172, 172, 170, 169, 167, 167, 165, 164, 162, 161, 159, 
157, 156, 155, 154, 151, 149, 148, 146, 144, 142, 141, 138, 137, 135, 133, 132, 129, 129, 127, 124, 
123, 121, 120, 118, 116, 115, 113, 111, 110, 108, 106, 105, 103, 102, 101, 99, 98, 96, 96, 95, 
95, 94, 93, 93, 92, 91, 92, 91, 90, 90, 90, 90, 88, 89, 89, 89, 89, 88, 89, 90, 
89, 90, 90, 90, 90, 91, 90, 90, 91, 91, 92, 92, 93, 93, 93, 94, 95, 95, 95, 95, 
95, 95, 96, 97, 96, 97, 98, 98, 99, 99, 100, 101, 101, 102, 102, 103, 103, 104, 105, 105, 
106, 106, 107, 108, 109, 110, 109, 111, 112, 112, 112, 113, 113, 114, 115, 116, 116, 117, 119, 120, 
120, 121, 121, 123, 124, 125, 126, 126, 127, 128, 129, 129, 130, 132, 133, 133, 134, 136, 135, 137, 
138, 139, 139, 140, 142, 143, 143, 145, 145, 147, 148, 149, 149, 150, 151, 152, 154, 155, 155, 156, 
157, 157, 159, 159, 160, 160, 161, 163, 162, 163, 163, 164, 164, 164, 164, 163, 164, 164, 164, 165, 
164, 164, 164, 164, 162, 162, 162, 163, 161, 161, 161, 160, 159, 159, 158, 157, 156, 155, 154, 154, 
153, 152, 151, 150, 148, 148, 147, 146, 145, 144, 143, 141, 140, 139, 138, 137, 136, 134, 133, 131, 
130, 129, 128, 126, 125, 124, 123, 121, 120, 119, 118, 118, 115, 115, 113, 112, 111, 110, 109, 108, 
108, 106, 105, 104, 104, 103, 102, 101, 100, 100, 100, 99, 99, 98, 97, 97, 98, 97, 98, 97, 
97, 97, 96, 96, 96, 97, 97, 97, 96, 98, 97, 99, 100, 99, 99, 100, 102, 102, 102, 103, 
103, 103, 105, 106, 107, 107, 108, 109, 111, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 
123, 124, 124, 125, 127, 128, 128, 130, 131, 132, 133, 134, 135, 136, 137, 136, 139, 139, 140, 141, 
142, 142, 143, 143, 145, 146, 146, 147, 148, 148, 149, 149, 149, 151, 149, 150, 151, 151, 152, 151, 
152, 152, 153, 153, 153, 152, 154, 153, 153, 153, 152, 151, 152, 153, 152, 151, 151, 150, 150, 150, 
149, 149, 148, 148, 147, 147, 146, 145, 145, 144, 144, 142, 142, 141, 140, 140, 138, 138, 137, 136, 
135, 134, 133, 134, 132, 131, 130, 129, 128, 127, 127, 125, 125, 124, 124, 122, 121, 120, 119, 120, 
119, 117, 118, 116, 115, 115, 114, 114, 112, 112, 111, 111, 110, 110, 109, 109, 109, 108, 107, 108, 
108, 108, 107, 107, 108, 107, 107, 106, 107, 107, 108, 106, 107, 107, 106, 108, 108, 107, 108, 109, 
109, 109, 110, 111, 111, 112, 111, 112, 112, 113, 113, 114, 114, 115, 115, 117, 117, 118, 118, 119, 
120, 120, 121, 121, 122, 124, 124, 125, 125, 126, 126, 128, 128, 129, 129, 130, 131, 131, 132, 133, 
133, 133, 135, 135, 135, 136, 137, 136, 138, 137, 138, 137, 139, 139, 140, 141, 140, 140, 141, 142, 
141, 142, 142, 142, 143, 142, 142, 143, 143, 143, 143, 143, 143, 143, 143, 143, 142, 143, 142, 143, 
142, 141, 142, 141, 141, 141, 141, 140, 140, 140, 139, 139, 138, 137, 139, 137, 136, 137, 136, 136, 
135, 135, 133, 135, 133, 134, 132, 132, 132, 130, 130, 129, 130, 128, 129, 127, 128, 126, 127, 125, 
126, 124, 123, 124, 123, 122, 122, 122, 121, 121, 120, 121, 120, 119, 118, 118, 118, 117, 117, 116, 
117, 116, 116, 116, 116, 114, 115, 114, 115, 116, 115, 114, 114, 114, 115, 114, 114, 115, 114, 115, 
114, 114, 115, 115, 115, 115, 115, 116, 115, 116, 116, 116, 116, 117, 117, 117, 118, 118, 119, 119, 
119, 120, 120, 120, 121, 120, 122, 122, 122, 123, 124, 124, 125, 126, 126, 127, 126, 128, 127, 129, 
127, 129, 129, 130, 129, 129, 132, 131, 132, 132, 133, 132, 134, 133, 135, 134, 134, 135, 135, 135, 
135, 137, 137, 136, 137, 137, 137, 137, 138, 137, 138, 139, 138, 139, 138, 138, 139, 139, 139, 139, 
139, 139, 139, 140, 139, 139, 139, 139, 139, 140, 139, 139, 139, 139, 139, 139, 139, 140, 138, 138, 
138, 137, 138, 138, 137, 137, 137, 136, 136, 136, 135, 136, 135, 135, 135, 133, 134, 133, 133, 133, 
133, 132, 132, 131, 131, 131, 130, 130, 130, 129, 129, 128, 128, 128, 127, 127, 126, 126, 125, 125, 
125, 125, 124, 124, 123, 124, 123, 122, 121, 122, 121, 121, 121, 120, 121, 120, 119, 119, 119, 119, 
119, 118, 117, 118, 118, 118, 117, 117, 117, 117, 117, 116, 116, 116, 115, 116, 116, 117, 116, 116, 
116, 116, 116, 116, 117, 118, 117, 117, 117, 117, 118, 118, 117, 118, 118, 119, 119, 119, 120, 120, 
120, 120, 121, 121, 122, 122, 122, 123, 123, 123, 124, 124, 124, 124, 124, 126, 126, 127, 127, 127, 
128, 128, 128, 129, 129, 129, 130, 130, 130, 132, 131, 131, 131, 132, 133, 133, 133, 134, 134, 133, 
134, 135, 135, 135, 136, 136, 136, 136, 137, 136, 136, 137, 138, 138, 136, 138, 137, 137, 137, 137, 
137, 137, 138, 137, 137, 136, 136, 137, 137, 137, 137, 136, 137, 137, 136, 135, 136, 136, 136, 135, 
135, 135, 135, 134, 134, 134, 133, 133, 133, 133, 132, 132, 132, 131, 130, 130, 129, 130, 130, 129, 
130, 128, 127, 128, 127, 128, 127, 127, 126, 127, 125, 125, 125, 124, 125, 124, 123, 123, 124, 123, 
122, 122, 122, 120, 121, 121, 121, 120, 120, 120, 121, 119, 119, 119, 119, 119, 118, 120, 119, 119, 
119, 119, 119, 118, 118, 119, 119, 119, 119, 119, 120, 119, 119, 119, 119, 119, 119, 120, 119, 120, 
121, 119, 120, 121, 122, 121, 122, 122, 123, 121, 122, 122, 123, 124, 123, 125, 124, 124, 126, 125, 
125, 126, 126, 127, 127, 127, 127, 128, 128, 128, 128, 129, 129, 130, 131, 130, 130, 131, 131, 131, 
131, 132, 133, 132, 133, 133, 133, 132, 133, 133, 134, 134, 134, 135, 134, 135, 135, 135, 134, 135, 
134, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 
135, 134, 134, 134, 134, 134, 134, 133, 133, 134, 133, 132, 132, 131, 132, 132, 131, 131, 132, 131, 
131, 130, 130, 129, 129, 128, 130, 128, 128, 128, 127, 127, 126, 127, 126, 126, 127, 126, 125, 125, 
125, 125, 124, 123, 124, 125, 124, 123, 123, 123, 123, 122, 121, 121, 122, 121, 122, 122, 121, 121, 
121, 121, 121, 121, 121, 121, 121, 122, 120, 121, 121, 122, 121, 121, 121, 122, 121, 121, 121, 122, 
120, 121, 121, 121, 121, 122, 122, 122, 122, 122, 121, 123, 123, 122, 123, 123, 124, 124, 125, 124, 
123, 125, 125, 125, 125, 126, 127, 126, 126, 127, 128, 127, 127, 127, 128, 128, 129, 129, 128, 128, 
129, 129, 129, 131, 130, 131, 130, 130, 131, 130, 131, 131, 131, 131, 131, 132, 132, 132, 132, 133, 
133, 134, 134, 132, 133, 133, 133, 133, 133, 133, 133, 134, 133, 133, 132, 133, 134, 133, 133, 132, 
133, 133, 133, 134, 133, 133, 133, 133, 133, 132, 132, 132, 132, 133, 133, 133, 131, 131, 131, 131, 
131, 131, 129, 129, 130, 130, 130, 129, 129, 129, 129, 129, 128, 128, 128, 128, 127, 127, 127, 127, 
127, 126, 127, 125, 126, 126, 126, 126, 126, 126, 125, 125, 124, 125, 125, 125, 124, 124, 123, 125, 
124, 124, 125, 123, 123, 123, 123, 123, 123, 123, 123, 122, 123, 123, 123, 123, 123, 123, 122, 122, 
123, 122, 124, 123, 123, 123, 123, 123, 122, 123, 123, 123, 123, 123, 124, 123, 123, 124, 123, 124, 
123, 124, 123, 124, 124, 124, 125, 125, 125, 126, 125, 125, 126, 125, 126, 126, 126, 126, 126, 126, 
127, 127, 127, 128, 127, 127, 127, 128, 128, 129, 128, 127, 127, 128, 130, 129, 130, 128, 129, 129, 
129, 129, 130, 130, 130, 130, 130, 130, 131, 130, 131, 131, 131, 131, 131, 131, 132, 131, 131, 131, 
131, 131, 131, 131, 131, 132, 132, 131, 131, 132, 131, 131, 131, 131, 130, 131, 132, 130, 131, 132, 
131, 131, 131, 131, 131, 130, 131, 130, 129, 129, 129, 130, 130, 130, 130, 130, 130, 128, 129, 129, 
129, 128, 129, 130, 129, 128, 128, 128, 128, 128, 128, 128, 127, 127, 127, 126, 128, 127, 127, 127, 
127, 127, 127, 126, 126, 127, 126, 126, 126, 127, 126, 126, 126, 126, 125, 125, 126, 125, 125, 126, 
124, 126, 125, 126, 125, 125, 125, 125, 124, 125, 125, 125, 125, 125, 125, 124, 125, 125, 125, 125, 
125, 125, 124, 125, 124, 126, 125, 124, 124, 124, 124, 126, 125, 127, 126, 127, 126, 126, 126, 126, 
127, 125, 125, 125, 127, 126, 127, 127, 127, 127, 127, 128, 127, 127, 127, 127, 127, 128, 128, 128, 
128, 128, 128, 127, 128, 127, 128, 128, 128, 128, 129, 129, 129, 129, 130, 129, 130, 128, 129, 129, 
128, 129, 129, 129, 130, 128, 129, 129, 129, 129, 130, 128, 129, 129, 129, 130, 129, 130, 129, 129, 
129, 129, 128, 128, 129, 129, 129, 129, 129, 129, 130, 129, 130, 129, 130, 129, 130, 129, 130, 128, 
128, 128, 128, 128, 128, 129, 128, 127, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, };
