#ifndef __LS_HC_SR04_h
#define __LS_HC_SR04_h

#include <stm32f1xx_hal.h>
#include "ls_beep.h"

typedef struct
{
    uint8_t  edge_state;
	uint16_t tim_overflow_counter;
	uint32_t t1;	//	上升沿时间
	uint32_t t2;	//	下降沿时间
	uint32_t high_level_us;	//	高电平持续时间
	float    distance;
}HcSrc04InfoTypeDef; 

extern HcSrc04InfoTypeDef HcSrc04Info;


#define TRIG_H()  (HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET))
#define TRIG_L()  (HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET))


void test(void);

#endif
