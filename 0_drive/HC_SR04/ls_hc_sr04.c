#include "ls_hc_sr04.h"
#include <stdio.h>
#include "tim.h"
     

HcSrc04InfoTypeDef HcSrc04Info; 
extern TIM_HandleTypeDef htim2;

void Trig_send(void)
{
    TRIG_H();
    delay_us(10);
    TRIG_L();
}

void Hcsr04Init(TIM_HandleTypeDef *htim)
{
     /*--------[ Start The ICU Channel ]-------*/
    HAL_TIM_Base_Start_IT(htim);
}
void test(void)
{
	uint16_t cont = 0;
	
	HAL_TIM_Base_Start_IT(&htim2);
	
	printf("test begin...\r\n");
	Trig_send();
	
	while (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_1) == 0);
	
	__HAL_TIM_SetCounter(&htim2, 0);
	
	while (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_1) == 1);
	
	HAL_TIM_Base_Stop(&htim2);
	
	cont = __HAL_TIM_GetCounter(&htim2);
	
	cont = (uint16_t)cont*0.017;
	
	printf("[%d]\n",cont);
}

