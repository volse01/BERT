#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

const int AirValue = 650;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
const int SensorPin = 26; //GP26
int soilMoisturePercent;
int soilMoistureValue;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
}

void loop() {
  // Your code here
  soilMoistureValue = analogRead(SensorPin);  //put Sensor insert into soil
  Serial.println(soilMoistureValue);
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  Serial.println(soilMoisturePercent)
  wait(5000) 
  
}