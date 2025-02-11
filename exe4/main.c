#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_RED = 5;
const int LED_PIN_PURPLE = 8;
const int LED_PIN_BLUE = 11;
const int LED_PIN_YELLOW = 15;
const int BTN_PIN = 28;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_RED);
  gpio_set_dir(LED_PIN_RED, GPIO_OUT);
  gpio_init(LED_PIN_PURPLE);
  gpio_set_dir(LED_PIN_PURPLE, GPIO_OUT);
  gpio_init(LED_PIN_BLUE);
  gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
  gpio_init(LED_PIN_YELLOW);
  gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if(!gpio_get(BTN_PIN)){
      gpio_put(LED_PIN_RED, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_RED, 0);
      gpio_put(LED_PIN_PURPLE, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_PURPLE, 0);
      gpio_put(LED_PIN_BLUE, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_BLUE, 0);
      gpio_put(LED_PIN_YELLOW, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_YELLOW, 0);
      while(!gpio_get(BTN_PIN)){
      };
    }
  }
}
