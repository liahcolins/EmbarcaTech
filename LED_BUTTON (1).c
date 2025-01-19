#include<stdio.h>
#include "pico/stdlib.h"

//define as portas
#define LED_PIN 11
#define BUTTON_PIN 5

int main () {
  //inicializa e configura os pinos como entrada ou sa�da
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  gpio_init(BUTTON_PIN);
  gpio_set_dir(BUTTON_PIN, GPIO_IN);

  while (true) {
    //get � como se fosse receber e put � literalmente colocar
    while (gpio_get(BUTTON_PIN)) {
      gpio_put(LED_PIN, 1);
    }
    gpio_put(LED_PIN, 0);
  }

}
