#ifndef __LS_BEEP_H
#define __LS_BEEP_H

#include <stm32f1xx_hal.h>

#define CPU_FREQUENCY_MHZ    72		// STM32时钟主频

#define BEEP_H()  (HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET))
#define BEEP_L()  (HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET))


void delay_us(__IO uint32_t delay);
void Beep_Power_on(void);
void Beep_Power_off(void);
void Beep_Button(void);

#endif // !__LS_BEEP_H
