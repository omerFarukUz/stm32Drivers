#include "GPIO.h"



/*
 * @brief		GPIO_Init, Configures the port and pins
 *
 * @param		GPIOx 	 		 --->> Port of GPIO (GPIOA,GPIOB,.. something like that)
 *
 * @param		GPIO_ConfigStruct --->> User config structure
 *
 * @retval		void
 */

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypedef_t *GPIO_ConfigStruct)
{
	uint32_t position;
	uint32_t fakePosition=0,lastPosition=0;

	for (position = 0; position < 16 ; position++)
	{
		fakePosition = (0x1 << position);
		lastPosition = ((uint32_t)(GPIO_ConfigStruct->pinNumber) & fakePosition) ;

		if (fakePosition == lastPosition)
		{

			/*MODE CONFIG */
			uint32_t tempValue = GPIOx->MODER;

			tempValue &= ~((0x3U) << (position*2) );
			tempValue |= (GPIO_ConfigStruct->Mode << (position*2));

			GPIOx->MODER = tempValue;

			if (GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_ALTERNATE )
			{
				/*OTYPE CONFIG */

				tempValue = GPIOx->OTYPER;
				tempValue &= ~(0x1 << position);
				tempValue |= (GPIO_ConfigStruct->Otype << position);
				GPIOx->OTYPER = tempValue;


				/*OSPEED CONFIG */

				tempValue = GPIOx->OSPEEDR;
				tempValue &= ~(0x3U << (position*2));
				tempValue |= (GPIO_ConfigStruct->Speed << (position*2));
				GPIOx->OSPEEDR = tempValue;

			}


			if (GPIO_ConfigStruct->Mode == GPIO_MODE_ALTERNATE)
			{
				/*ALTERNATE FUNCTON CONFIG */

				tempValue = GPIOx->AFR[position >> 3U];
				tempValue &= ~(0xFU << ((position & 0x7U)*4));
				tempValue |= (GPIO_ConfigStruct->Alternate << ((position & 0x7U)*4));
				GPIOx->AFR[position >> 3U] = tempValue;
			}



			/*PUPDR CONFIG */

			tempValue = GPIOx->PUPDR;
			tempValue &= ~(0x3U << (position*2));
			tempValue |= (GPIO_ConfigStruct->PuPd << (position*2));
			GPIOx->PUPDR = tempValue;

		}


	}

}




/*
 * @brief		GPIO_WritePin, writes "1" or "0" to GPIO pin register
 *
 * @param		GPIOx 	  --->> Port of GPIO (GPIOA,GPIOB,.. something like that)
 *
 * @param		pinNumber --->> GPIO Pin Numbers (0-15)
 *
 * @param		pinState  --->> GPIO Pin Set OR GPIO Pin Reset
 *
 * @retval		void
 */

void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNmuber, GPIO_PinState_t pinState )
{

	if(pinState==GPIO_Pin_Set)
	{
		GPIOx->BSRR = pinNmuber;
	}
	else
	{
		GPIOx->BSRR = (pinNmuber << (16U));
	}

}




/*
 * @brief		GPIO_ReadPin,  reads from GPIOs pin register status
 *
 * @param		GPIOx 	  --->> Port of GPIO (GPIOA,GPIOB,.. something like that)
 *
 * @param		pinNumber --->> GPIO Pin Numbers (0-15)
 *
 * @retval		bitStatus
 */

GPIO_PinState_t	GPIO_ReadPin (GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	GPIO_PinState_t bitStatus = GPIO_Pin_Reset;

	if ((GPIOx->IDR & pinNumber)!= GPIO_Pin_Reset )
	{
		bitStatus = GPIO_Pin_Set;
	}

	return bitStatus;
}





/*
 * @brief		GPIO_LockPin, locks to write nothings to GPIO pin register
 *
 * @param		GPIOx 	  --->> Base Address of GPIO Port(GPIOA,GPIOB,.. something like that)
 *
 * @param		pinNumber --->> GPIO Pin Numbers (0-15)
 *
 * @retval		void
 */


void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	uint32_t tempValue = (0x1U << 16U) |pinNumber ;

	GPIOx->LCKR = tempValue;		//WR LCKR[16] = ‘1’ + LCKR[15:0]
	GPIOx->LCKR = pinNumber;		//WR LCKR[16] = ‘1’ + LCKR[15:0]
	GPIOx->LCKR = tempValue;		//WR LCKR[16] = ‘1’ + LCKR[15:0]
	tempValue = GPIOx->LCKR;		//read lock register


}


void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx , uint16_t pinNumber)
{
	uint32_t tempValue = GPIOx->ODR ;
	GPIOx->BSRR = ((tempValue & pinNumber) << 16U) | (~tempValue & pinNumber);

}










