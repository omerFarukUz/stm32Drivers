#include "stm32f439xx.h"


SPI_HandleTypeDef_t SPI_Handle;


static void GPIO_Led_Config();
//static void GPIO_LockControl();
static void	GPIO_ButtonInterruptConfig();
static void SPI_Config();
static void SPI_GPIO_Config();






void EXTI15_10_IRQHandler()
{
	char msgToSend[] = "Hello World!\n";

	if (EXTI->PR & 0x2000)
	{
		EXTI->PR |= (0x1 << 13U);
		//GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_Pin_Set);

		SPI_TransmitData_IT(&SPI_Handle, (uint8_t*)msgToSend, strlen(msgToSend));

	}


}


void SPI1_IRQHandler()
{
	SPI_InterruptHandler(&SPI_Handle);

}



int main(void)
{

 	GPIO_Led_Config();

	//GPIO_LockPin(GPIOC, GPIO_PIN_13);


	//GPIO_LockControl();

	GPIO_ButtonInterruptConfig();

	SPI_GPIO_Config();

	SPI_Config();



    /* Loop forever */
	for(;;)
	{


	}
}

static void GPIO_Led_Config()
{

	GPIO_InitTypedef_t GPIO_InitStruct_t = {0};
	RCC_SYSCFG_CLK_ENABLE();
	RCC_SPI1_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();
	RCC_GPIOC_CLK_ENABLE();
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOE_CLK_ENABLE();


	GPIO_InitStruct_t.pinNumber = GPIO_PIN_7 | GPIO_PIN_14;
	GPIO_InitStruct_t.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct_t.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct_t.Speed = GPIO_OSPEED_LOW;
	GPIO_InitStruct_t.PuPd = GPIO_PUPD_NOPULL;


	GPIO_Init(GPIOB, &GPIO_InitStruct_t);

	memset(&GPIO_InitStruct_t , 0 , sizeof(GPIO_InitStruct_t));

	GPIO_InitStruct_t.pinNumber = GPIO_PIN_13;
	GPIO_InitStruct_t.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct_t.PuPd = GPIO_PUPD_PULLDOWN;

	GPIO_Init(GPIOC, &GPIO_InitStruct_t);



}

/*
static void GPIO_LockControl()
{
	GPIO_InitTypedef_t GPIO_InitStruct_t = {0};

	GPIO_InitStruct_t.pinNumber = GPIO_PIN_13;
	GPIO_InitStruct_t.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct_t.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOC, &GPIO_InitStruct_t);

}
*/

static void	GPIO_ButtonInterruptConfig()
{
	EXTI_InitTypeDef_t EXTI_InitStruct = {0};


	EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_13);


	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_MODE_Interrupt;
	EXTI_InitStruct.EXTI_LineNumber = EXTI_LineSource_13;
	EXTI_InitStruct.TriggerSelection = EXTI_TRIGGER_Rising;

	EXTI_Init(&EXTI_InitStruct);

	NVIC_EnableInterrupt(EXTI13_IRQNumber);

}




static void SPI_Config()
{

	//SPI_HandleTypeDef_t SPI_Handle = {0};



	SPI_Handle.Instance = SPI1;

	SPI_Handle.Init.Baudrate = SPI_BAUDRATE_DIV32;
	SPI_Handle.Init.BusConfig = SPI_BUS_FullDuplex;
	SPI_Handle.Init.CPHA = SPI_CPHA_FIRST_EDGE;
	SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
	SPI_Handle.Init.DFF_Format = SPI_DFF_8BITS;
	SPI_Handle.Init.FrameFormat = SPI_FRAMEFORMAT_MSB;
	SPI_Handle.Init.Mode = SPI_MASTER_MODE;
	SPI_Handle.Init.SSM_Cmd = SPI_SSM_ENABLE;

	SPI_Init(&SPI_Handle);

	NVIC_EnableInterrupt(SPI1_IRQNumber);

	SPI_Activate(&SPI_Handle, ENABLE);


}


static void SPI_GPIO_Config()
{

	GPIO_InitTypedef_t GPIO_InitStruct = {0};


	GPIO_InitStruct.pinNumber = GPIO_PIN_5 | GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed = GPIO_OSPEED_VERYHIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5;

	GPIO_Init(GPIOA, &GPIO_InitStruct);
}






