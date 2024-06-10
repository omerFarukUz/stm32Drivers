#include "stm32f439xx.h"

USART_HandleTypedef_t USART_Handle;

static void GPIO_Config(void);
static void UART_Config(void);


int main(void)
{

	//char msgToSend[]= "Hey Bro How Are You?\n";
	char receiveData[]="Hey Bro How Are You?\n";

	GPIO_Config();
	UART_Config();

	USART_ReceiveData_IT(&USART_Handle, (uint8_t*)receiveData, 20);
	USART_TransmitData_IT(&USART_Handle, (uint8_t*)receiveData, strlen(receiveData));



	/*
	USART_ReceiveData(&USART_Handle, (uint8_t*)msgToSend, 12);
	USART_TransmitData(&USART_Handle, (uint8_t*)msgToSend, strlen(msgToSend));*/


	while(1);
}



void USART2_IRQHandler()
{
	USART_InterruptHandler(&USART_Handle);
}





static void UART_Config(void)
{
	RCC_USART2_CLK_ENABLE();

	USART_Handle.Instance = USART2;
	USART_Handle.Init.Baudrate = 19200;
	USART_Handle.Init.HardwareFlowControl = USART_HW_NONE;
	USART_Handle.Init.Mode = USART_MODE_Tx_Rx;
	USART_Handle.Init.OverSampling = USART_OVERSAMPLING_16;
	USART_Handle.Init.Parity = USART_PARITY_NONE;
	USART_Handle.Init.StopBits = USART_STOPBITS_1;
	USART_Handle.Init.WorldLength = USART_LENGTH_8Bits;


	USART_Init(&USART_Handle);

	NVIC_EnableInterrupt(USART2_IRQn);

	USART_Active(&USART_Handle, ENABLE);

}

static void GPIO_Config(void)
{
	GPIO_InitTypedef_t GPIO_InitStruct = {0};

	RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.pinNumber = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed = GPIO_OSPEED_VERYHIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7;

	GPIO_Init(GPIOA,&GPIO_InitStruct);


}






