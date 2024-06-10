#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f439xx.h"

/*
 *  RCC AHB1 Peripherals Clock Control Macro Definitions
 *
 */


#define RCC_GPIOA_CLK_ENABLE()				do{	uint32_t  tempValue=0; 									\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);				\
												tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);	\
												UNUSED(tempValue);										\
											  }while(0)

#define RCC_GPIOB_CLK_ENABLE()				do{	uint32_t  tempValue=0; 									\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);				\
												tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);	\
												UNUSED(tempValue);										\
											  }while(0)

#define RCC_GPIOC_CLK_ENABLE()				do{	uint32_t  tempValue=0; 									\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);				\
												tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);	\
												UNUSED(tempValue);										\
											  }while(0)

#define RCC_GPIOD_CLK_ENABLE()				do{	uint32_t  tempValue=0; 									\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);				\
												tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);	\
												UNUSED(tempValue);										\
											  }while(0)

#define RCC_GPIOE_CLK_ENABLE()				do{	uint32_t  tempValue=0; 									\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);				\
												tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);	\
												UNUSED(tempValue);										\
											  }while(0)


#define RCC_SYSCFG_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFG);		       \
												tempValue=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFG);   \
												UNUSED(tempValue);									   \
											  }while(0)




#define RCC_GPIOA_CLK_DISABLE()				CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN)
#define RCC_GPIOB_CLK_DISABLE()				CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN)
#define RCC_GPIOC_CLK_DISABLE()				CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN)
#define RCC_GPIOD_CLK_DISABLE()				CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN)



/*
 *  RCC APB1 Peripherals Clock Control Macro Definitions
 *
 */



#define RCC_SPI2_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2);			       \
												tempValue=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2);	   \
												UNUSED(tempValue);									   \
											  }while(0)

#define RCC_SPI3_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3);			       \
												tempValue=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3);	   \
												UNUSED(tempValue);									   \
											  }while(0)

#define RCC_USART2_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2);			       \
												tempValue=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2);	   \
												UNUSED(tempValue);									   \
											  }while(0)

#define RCC_USART3_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART3);			       \
												tempValue=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_USART3);	   \
												UNUSED(tempValue);									   \
											  }while(0)




#define RCC_SPI2_CLK_DISABLE()				CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2)
#define RCC_SPI3_CLK_DISABLE()				CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3)
#define RCC_USART2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2)


#define RCC_I2C1_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C1);			       \
												tempValue=READ_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C1);	   \
												UNUSED(tempValue);									   \
											  }while(0)

#define RCC_I2C1_CLK_DISABLE()				CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_I2C1)





/*
 *  RCC APB2 Peripherals Clock Control Macro Definitions
 *
 */



#define RCC_SPI1_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1);			       \
												tempValue=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1);	   \
												UNUSED(tempValue);									   \
											  }while(0)



#define RCC_SPI4_CLK_ENABLE()				do{ uint32_t tempValue=0;\
												SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4);			       \
												tempValue=READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4);	   \
												UNUSED(tempValue);									   \
											  }while(0)




#define RCC_SPI1_CLK_DISABLE()				CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1)
#define RCC_SPI4_CLK_DISABLE()				CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4)




uint32_t RCC_GetSystemClock(void);
uint32_t RCC_GetHClock(void);
uint32_t RCC_GetPClock1(void);
uint32_t RCC_GetPClock2(void);


#endif /* INC_RCC_H_ */
