#include "ls_beep.h"

void LS_Beep_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  LS_BEEP_CLK();

  /*Configure GPIO pins : PG6 PG7 */
  GPIO_InitStruct.Pin = LS_BEEP_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LS_BEEP_PORT, &GPIO_InitStruct);
}


void Beep_Power_on(void)
{
    BEEP_L();
    BEEP_H();
    HAL_Delay(80);
    BEEP_L();
    HAL_Delay(80);
    BEEP_H();
    HAL_Delay(30);
    BEEP_L();
    HAL_Delay(280);
    BEEP_H();
    HAL_Delay(50);
    BEEP_L();
}
void Beep_Power_off(void)
{
    BEEP_L();
    BEEP_H();
    HAL_Delay(30);
    BEEP_L();
    HAL_Delay(280);
    BEEP_H();
    HAL_Delay(30);
    BEEP_L();
    HAL_Delay(80);
    BEEP_H();
    HAL_Delay(80);
    BEEP_L();
}
void Beep_Button(void)
{
    BEEP_H();
    HAL_Delay(1);
    BEEP_L(); 
}

void delay_us(__IO uint32_t delay)
{
    int last, curr, val;
    int temp;

    while (delay != 0)
    {
        temp = delay > 900 ? 900 : delay;
        last = SysTick->VAL;
        curr = last - CPU_FREQUENCY_MHZ * temp;
        if (curr >= 0)
        {
            do
            {
                val = SysTick->VAL;
            }
            while ((val < last) && (val >= curr));
        }
        else
        {
            curr += CPU_FREQUENCY_MHZ * 1000;
            do
            {
                val = SysTick->VAL;
            }
            while ((val <= last) || (val > curr));
        }
        delay -= temp;
    }
}

