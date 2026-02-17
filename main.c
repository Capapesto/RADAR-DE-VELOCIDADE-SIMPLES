#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define PIR1 13
#define PIR2 35

void app_main() {
    gpio_set_direction(PIR1, GPIO_MODE_INPUT);
    gpio_set_direction(PIR2, GPIO_MODE_INPUT);

    int tempo = 0;
    const int distancia = 10; 

    while (1) {
        if (gpio_get_level(PIR1) == 1) {
            tempo = 0; // Zera o cronômetro
            printf("Iniciou contagem...\n");

            //Enquanto o sensor 2 NÃO detectar nada, ele soma tempo
            while (gpio_get_level(PIR2) == 0) {
                vTaskDelay(100 / portTICK_PERIOD_MS); // Espera 0.1 segundo
                tempo++; // Aumenta o contador
            }

            // Quando o sensor 2 detectar, ele sai do 'while'
            // Velocidade = Distância / (tempo * 0.1)
            // *3.6 = conversão km/h
            float velocidade = (distancia / (tempo * 0.1)) * 3.6;

            printf("Velocidade: %.1f Km/h\n", velocidade);
            
            
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            printf("reset\n");
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
        
    }
}
