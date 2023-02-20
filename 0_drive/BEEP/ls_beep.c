#include "ls_beep.h"


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

