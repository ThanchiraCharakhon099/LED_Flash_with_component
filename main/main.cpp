#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16); 
LED led2(17); 
LED led3(5); 
LED led4(18); 
LED led5(19); 
LED led6(21); 
LED led7(22); 
LED led8(23); 

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

extern "C" void app_main(void)
{
    int left_index = 0;
    int right_index = 7;

    while(1)
    {        
        leds[left_index].ON();
        leds[right_index].ON();
        
        vTaskDelay(500 / portTICK_PERIOD_MS);

        leds[left_index].OFF();
        leds[right_index].OFF();

        if(++left_index > 3) left_index = 0;
        if(--right_index < 4) right_index = 7;
    }
}
