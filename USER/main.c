#include "main.h"


// Private variables


// Calling function



// FreeRTOS Task
void led1_task(void *p);
void ledGREEN_task(void *p);
void ledRED_task(void *p);
void ledBLUE_task(void *p);


int main(void)
{
	
	/* Halting the Watchdog */
	MAP_WDT_A_holdTimer();
	
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2);
	
	MAP_SysTick_enableModule();
	MAP_SysTick_setPeriod(48000000);
	
	xTaskCreate(led1_task,(const char*)"LED1",256,NULL,1,NULL);
	xTaskCreate(ledBLUE_task,(const char*)"LED BLUE",32,NULL,1,NULL);
	xTaskCreate(ledGREEN_task,(const char*)"LED GREEN",32,NULL,1,NULL);
	xTaskCreate(ledRED_task,(const char*)"LED RED",32,NULL,1,NULL);
	
	vTaskStartScheduler();
	
	
	
	while(1)
	{
//		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, (7<<0));
//		for(volatile uint32_t i=0;i<500000;i++);
		__delay_cycles(1000000);
	}
}

void led1_task(void *p)
{
	while(1)
	{
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
		vTaskDelay(100);
	}
}




// RED LED task
void ledRED_task(void *p)
{
	while(1)
	{
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2,GPIO_PIN0);
		vTaskDelay(100);
	}
}

// BLUE LED Task
void ledBLUE_task(void *p)
{
	while(1)
	{
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2,GPIO_PIN1);
		vTaskDelay(200);
	}
}

// GREE LED Task
void ledGREEN_task(void *p)
{
	while(1)
	{
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2,GPIO_PIN2);
		vTaskDelay(150);
	}
}