#include "EXTI.h"


/*
 * @brief		EXTI_Init , Init GPIO port and Line number
 *
 * @param		EXTI_InitStruct 	 		 --->> User config structure
 *
 * @retval		void
 */



void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct)
{
	uint32_t tempValue = 0;

	tempValue = (uint32_t)EXTI_BASE_ADDR;

	EXTI->IMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	if (EXTI_InitStruct->EXTI_LineCmd != DISABLE)
	{
		tempValue += EXTI_InitStruct->EXTI_Mode;

		*((__IO uint32_t*) tempValue) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue = (uint32_t)EXTI_BASE_ADDR;

		EXTI->RTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

		if (EXTI_InitStruct->TriggerSelection == EXTI_TRIGGER_All)
		{
			EXTI->RTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}
		else
		{
			tempValue += EXTI_InitStruct->TriggerSelection;

			*((__IO uint32_t*) tempValue) |= (0x01U << EXTI_InitStruct->EXTI_LineNumber);
		}

	}
	else
	{
		tempValue = (uint32_t)EXTI_BASE_ADDR;

		tempValue += EXTI_InitStruct->EXTI_Mode;

		*((__IO uint32_t*) tempValue) &= ~(0x01U << EXTI_InitStruct->EXTI_LineNumber);

	}



}


/*
 * @brief		EXTI_LineConfig , Configures the port and pins for SYSCFG
 *
 * @param		PortSource 	 		 --->> Port of GPIO (GPIOA,GPIOB,.. something like that) @def_group PORT_Values
 *
 * @param		EXTI_LineSource		 --->> Number of EXTI lines  @def_group EXTI_Line_Values
 *
 * @retval		void
 */

void EXTI_LineConfig(uint8_t PortSource , uint8_t EXTI_LineSource)
{

	uint32_t tempValue;
	tempValue = SYSCFG->EXTI_CR[EXTI_LineSource>>2];
	tempValue &= ~(0xF << ((EXTI_LineSource & 0x3U)*4));
	tempValue = (PortSource<<(EXTI_LineSource & 0x3U)*4);
	SYSCFG->EXTI_CR[EXTI_LineSource>>2] = tempValue;


}

/*
 * @brief		NVIC_EnableInterrupt
 *
 * @param		IRQNumber   --->> IRQNumber of the Line
 * @retval		void
 */

void NVIC_EnableInterrupt(IRQNumber_TypeDef_t IRQNumber)
{
	uint32_t tempValue = 0;

	tempValue = *((IRQNumber>>5U) + NVIC_ISER0); // ilgili registerin adresini bulduk
	tempValue &= ~(0x01U << (IRQNumber & 0x1FU)); // ilgili register'a bit seviyesinde ulastik ve temizledik
	tempValue |= (0x01U << (IRQNumber & 0x1FU));  // ilgili register'a istenilen degeri verdik yani enable ettik
	*((IRQNumber>>5U) + NVIC_ISER0) = tempValue;

}




