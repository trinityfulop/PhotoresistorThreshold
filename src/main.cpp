#include <Arduino.h>

int lastlightValue1 = 0;
int lastlightValue2 = 0;
int lastlightValue3 = 0;
int threshold = 200;   
// what is the threshold for light vs darkness? dark > 200 to 400, light > 700 to 800

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (A3, INPUT);
}

void loop() {
  // Sensor 1
 int lightValue1 = analogRead(A0);
  // if it's below the threshold?
  if (lightValue1 <= threshold) {
     if (lastlightValue1 > threshold) {
        // the sensor just crossed the threshold
        Serial.println("Light Value right sensor 1 crossed the threshold LOW");
     }
  }
  lastlightValue1 = lightValue1;

// Sensor 2
  int lightValue2 = analogRead(A1);
  if (lightValue2 <= threshold) {
     if (lastlightValue2 > threshold) {
        // the sensor just crossed the threshold
        Serial.println("Light Value center sensor 2 crossed the threshold LOW");
     }
  }
  lastlightValue2 = lightValue2;

  // Sensor 3
  int lightValue3 = analogRead(A2);
  if (lightValue3 <= threshold) {
     if (lastlightValue3 > threshold) {
        // the sensor just crossed the threshold
        Serial.println("Light Value left sensor 3 crossed the threshold LOW");
     }
  }
  lastlightValue3 = lightValue3;
}