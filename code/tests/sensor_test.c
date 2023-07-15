#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
#include <unistd.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
//#include "hardware/pwm.h"

//defining the pins
#define Sensor_Power_PIN 22
#define ADC_PIN 26

//declaring the variable to save the wettness
uint16_t soilMoistureValue;

void main (void) {
  
  // Initialize serial and wait for port to open:
    stdio_init_all();

  gpio_init(Sensor_Power_PIN);
  gpio_set_dir(Sensor_Power_PIN, GPIO_OUT);
  gpio_put(Sensor_Power_PIN, 1);
  sleep_ms(200);

  adc_init();
  adc_gpio_init(ADC_PIN);
  
  while (1){
  //testing the sensors and printing their values in the terminal 
    adc_select_input(2);
    for (int i=0; i<200; i++){
      soilMoistureValue += adc_read();
      sleep_ms(10);
    }

    soilMoistureValue = soilMoistureValue/200;
    printf("%d\n", soilMoistureValue);      
     
  }
}