#include "ls_exti.h"

void Ls_Exti_Init(uint32_t PreemptPriority, uint32_t SubPriority)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	/* GPIO Ports Clock Enable */
	LS_EXTI_CLK();

	/*Configure GPIO pin : PE2 */
	GPIO_InitStruct.Pin = LS_EXTI_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;	/*interrupt trigger*/
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(LS_EXTI_PORT, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(LS_EXTI_IRQn, PreemptPriority, SubPriority);
	HAL_NVIC_EnableIRQ(LS_EXTI_IRQn);
}

void LS_EXTI_IRQHander(void)
{
  /* USER CODE BEGIN EXTI2_IRQn 0 */
	if (__HAL_GPIO_EXTI_GET_IT(LS_EXTI_PIN) != RESET)
	{
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
		__HAL_GPIO_EXTI_CLEAR_IT(LS_EXTI_PIN);
	}
  /* USER CODE END EXTI2_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
  /* USER CODE BEGIN EXTI2_IRQn 1 */

  /* USER CODE END EXTI2_IRQn 1 */
}

