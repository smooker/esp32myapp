#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "esp_system.h"
//#include  "esp_event.h"
#include "driver/gpio.h"
//#include "sdkconfig.h"

#define BLINK_GPIO 2

/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter )
{
    /* loop forever */
    for(;;)
    {
        printf("this is another Task\n");
        vTaskDelay(600 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    xTaskCreate(
    anotherTask, /* Task function. */
    "another Task", /* name of task. */
    10000, /* Stack size of task */
    NULL, /* parameter of the task */
    1, /* priority of the task */
    NULL); /* Task handle to keep track of created task */

    int i = 0;
    while (1) {
        printf("[%d] Hello world!\n", i);
        i++;
        gpio_set_level(BLINK_GPIO,i%2);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
