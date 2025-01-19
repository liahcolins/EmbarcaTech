//Liah Renata Colins da Silva

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LEDR 12 //red
#define LEDG 11 //green
#define LEDB 13 //blue

void led_rgb_set (bool r, bool g, bool b) {
    gpio_put(LEDR, r);
    gpio_put(LEDG, g);
    gpio_put(LEDB, b);
}

int main() {
    stdio_init_all();

    gpio_init(LEDR);
    gpio_init(LEDG);
    gpio_init(LEDB);
    gpio_set_dir(LEDR, true);
    gpio_set_dir(LEDG, true);
    gpio_set_dir(LEDB, true);

    while (true) {
        led_rgb_set(true, false, false); //led vermelho
        sleep_ms(500);

        led_rgb_set(false, true, false); //led verde
        sleep_ms(500);

        led_rgb_set(false, false, true); //led azul
        sleep_ms(500);

        led_rgb_set(true, true, true); //todos os leds
        sleep_ms(500);
    }
}
