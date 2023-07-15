#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define Sensor_Power_PIN 31
#define ADC_PIN0 26
#define ADC_PIN1 28
#define ADC_PIN2 29

int soilMoistureValue [3];

int main (void) {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  stdio_init_all();

  gpio_init(Sensor_Power_PIN);
  gpio_set_dir(Sensor_Power_PIN, GPIO_OUT);

  adc_init();
  adc_gpio_init(ADC_PIN0);
  adc_gpio_init(ADC_PIN1);
  adc_gpio_init(ADC_PIN2);

  adc_select_input(0);  // Select ADC input 0 (GPIO 26)
  adc_select_input(1);  // Select ADC input 1 (GPIO 28)
  adc_select_input(2);  // Select ADC input 2 (GPIO 29)
 
  while (1){
  //testing the sensors and printing their values in the terminal 
    for (int i; i < 3; i++) { 
      gpio_put(Sensor_Power_PIN, 1);
      sleep_ms(200);

      soilMoistureValue[i] = adc_read(i) 
      Serial.println(i, ":", soilMoistureValue );
      
    }
    sleep(5);
  }
  return 0;
}