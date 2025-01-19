#include<stdio.h>
#include "pico/stdlib.h"

//define as portas
#define LEDB_PIN 11
#define LEDR_PIN 10
#define LEDG_PIN 9
#define BUTTONA_PIN 4
#define BUTTONB_PIN 5

int main () {
  //inicializa e configura os pinos como entrada ou saída
  gpio_init(LEDB_PIN);
  gpio_set_dir(LEDB_PIN, GPIO_OUT);

  gpio_init(LEDR_PIN);
  gpio_set_dir(LEDR_PIN, GPIO_OUT);

  gpio_init(LEDG_PIN);
  gpio_set_dir(LEDG_PIN, GPIO_OUT);

  gpio_init(BUTTONA_PIN);
  gpio_set_dir(BUTTONA_PIN, GPIO_IN);

  gpio_init(BUTTONB_PIN);
  gpio_set_dir(BUTTONB_PIN, GPIO_IN);

  while (true) {
    //get é como se fosse receber e put é literalmente colocar
    if (gpio_get(BUTTONA_PIN)) {
      gpio_put(LEDB_PIN, 1);
      gpio_put(LEDR_PIN, 0);
      gpio_put(LEDG_PIN, 0);
      sleep_ms(100);
    } else if (gpio_get(BUTTONB_PIN)) {
      gpio_put(LEDB_PIN, 0);
      gpio_put(LEDR_PIN, 1);
      gpio_put(LEDG_PIN, 0);
    } else {
      gpio_put(LEDB_PIN, 0);
      gpio_put(LEDR_PIN, 0);
      gpio_put(LEDG_PIN, 1);
    }
  }

}
