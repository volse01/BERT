#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

const int AirValue = 650;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
const int SensorPin = 26; //A0
int soilMoisturePercent[];
int soilMoistureValue[];

int main (void) {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);


  while (true){
  //testing the sensors in the terminal 
    for (int i, i < 4, i++) {  
      soilMoistureValue = analogRead(SensorPin+i); 

      if (i==0){
        i++;
      } 

      Serial.println(soilMoistureValue, i \n);
      soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
      Serial.println(soilMoisturePercent, i "%"\n);
      wait(5000);
    }
  }
  return 0;
}