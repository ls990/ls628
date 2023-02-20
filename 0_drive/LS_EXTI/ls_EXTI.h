#ifndef __LS_EXTI_H
#define __LS_EXTI_H

#include  <stm32f1xx_hal.h>

#define LS_EXTI_IRQn		EXTI2_IRQn
#define LS_EXTI_PIN		GPIO_PIN_2
#define LS_EXTI_PORT		GPIOE
#define LS_EXTI_CLK()	__HAL_RCC_GPIOE_CLK_ENABLE()
#define LS_EXTI_IRQHander	EXTI2_IRQHandler

#endif

