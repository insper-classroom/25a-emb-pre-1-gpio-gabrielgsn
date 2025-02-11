#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_RED_PIN = 4;
const int LED_GREEN_PIN = 6;
const int BTN_RED_PIN = 28;
const int BTN_GREEN_PIN = 26;

int main() {
  stdio_init_all();

  int status_red = 1;
  int status_green = 1;

  gpio_init(LED_RED_PIN);
  gpio_set_dir(LED_RED_PIN, GPIO_OUT);
  gpio_init(LED_GREEN_PIN);
  gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
  gpio_init(BTN_RED_PIN);
  gpio_set_dir(BTN_RED_PIN, GPIO_IN);
  gpio_pull_up(BTN_RED_PIN);
  gpio_init(BTN_GREEN_PIN);
  gpio_set_dir(BTN_GREEN_PIN, GPIO_IN);
  gpio_pull_up(BTN_GREEN_PIN);



  while (true) {
    if (!gpio_get(BTN_RED_PIN)){
      gpio_put(LED_RED_PIN, status_red);
      status_red = !status_red;
      while(!gpio_get(BTN_RED_PIN)){
      };
    }
    if (!gpio_get(BTN_GREEN_PIN)){
      gpio_put(LED_GREEN_PIN, status_green);
      status_green = !status_green;
      while(!gpio_get(BTN_GREEN_PIN)){
      };
    }
  }
}
