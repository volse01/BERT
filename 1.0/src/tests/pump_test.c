#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

//defining the pins
#define Pump_1_PIN 11
#define Pump_2_PIN 12
#define Pump_3_PIN 13

//definig the pump duration
#define PumpDuration 10000

void main (void) {
  
  // Initialize serial and wait for port to open:
  stdio_init_all();

  //initializing the Pins
  gpio_init(Pump_1_PIN);
  gpio_init(Pump_2_PIN);
  gpio_init(Pump_3_PIN);
  gpio_set_dir(Pump_1_PIN, GPIO_OUT);
  gpio_set_dir(Pump_2_PIN, GPIO_OUT);
  gpio_set_dir(Pump_3_PIN, GPIO_OUT);
  
  while (1){
  
  gpio_put(Pump_1_PIN, 1);
  sleep_ms(2000);
  gpio_put(Pump_2_PIN, 1);
  sleep_ms(2000);
  gpio_put(Pump_3_PIN, 1);

  sleep_ms(PumpDuration);

  gpio_put(Pump_1_PIN, 0);
  gpio_put(Pump_2_PIN, 0);
  gpio_put(Pump_3_PIN, 0);   

  sleep_ms(PumpDuration);
  }
}