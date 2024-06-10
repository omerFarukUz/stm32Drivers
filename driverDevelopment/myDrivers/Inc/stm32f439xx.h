/*
 * stm32f439xx.h
 *
 *  Created on: Jan 14, 2024
 *      Author: omer
 */

#ifndef INC_STM32F439XX_H_
#define INC_STM32F439XX_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>


/*
 *
 * Microprocessor defines
 *
 */

#define NVIC_ISER0						(uint32_t*)(0xE000E100)




#define __IO volatile

/*
 * Macros about BIT
 *
 */
#define SET_BIT(REG,BIT)				((REG)|=(BIT))
#define CLEAR_BIT(REG,BIT)				((REG)&=~(BIT))
#define READ_BIT(REG,BIT)				((REG)&(BIT))
#define UNUSED(x)						(void)x

typedef enum
{
	DISABLE = 0x0,
	ENABLE = !DISABLE
}FunctionalState_t;

/*
 * IRQ Numbers of MCU
 *
 */

typedef enum
{
	EXTI13_IRQNumber=40,
	SPI1_IRQNumber=35,
	SPI4_IRQNumber=84,
	EXTI3_IRQNumber=9,
	EXTI7_IRQNumber=30,
	USART2_IRQn = 38

}IRQNumber_TypeDef_t;



/*
 * Memory Base Address
 *
 */

#define FLASH_BASE_ADDR        (0x08000000UL)                          /* Flash Base Address (up to 2 MB)  					    */
#define CCM_BASE_ADDR   	   (0x10000000UL)	                       /* CCM(core coupled memory) data RAM(64 KB) base address */
#define SRAM1_BASE_ADDR		   (0x20000000UL)       	  			   /* SRAM1 Base Address 112KB  							*/
#define SRAM2_BASE_ADDR		   (0x2001C000UL)	    	  			   /* SRAM2 Base Address 64KB  								*/
#define SRAM3_BASE_ADDR		   (0x20020000UL)	    	  			   /* SRAM3 Base Address  									*/


/*
 * Peripheral Base Addresses
 *
 */

#define PERIHP_BASE_ADDR	   (0x40000000UL)	    	  			   /* Base Address of All Peripherals Address 				*/

#define APB1_BASE_ADDR		   (PERIHP_BASE_ADDR )    	  			   /* APB1 Bus Domain Base Address 							*/
#define APB2_BASE_ADDR		   (PERIHP_BASE_ADDR + 0x00010000UL)	   /* APB2 Bus Domain Base Address 							*/
#define AHB1_BASE_ADDR		   (PERIHP_BASE_ADDR + 0x00020000UL)	   /* AHB1 Bus Domain Base Address 							*/
#define AHB2_BASE_ADDR		   (PERIHP_BASE_ADDR + 0x10000000UL) 	   /* AHB2 Bus Domain Base Address 							*/

/*
 * APB1 Peripheral Base Addresses
 *
 */

#define TIM2_BASE_ADDR			(APB1_BASE_ADDR + 0x00000000UL)				/* Timer2 Base Address 									*/
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR + 0x00000400UL)				/* Timer3 Base Address 									*/
#define TIM4_BASE_ADDR			(APB1_BASE_ADDR + 0x00000800UL)				/* Timer4 Base Address 									*/
#define TIM5_BASE_ADDR			(APB1_BASE_ADDR + 0x00000C00UL)				/* Timer5 Base Address 									*/
#define TIM6_BASE_ADDR			(APB1_BASE_ADDR + 0x00001000UL)				/* Timer6 Base Address 									*/
#define TIM7_BASE_ADDR			(APB1_BASE_ADDR + 0x00001400UL)				/* Timer7 Base Address 									*/


#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x00003800UL)				/* SPI2  Base Address 									*/
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x00003C00UL)				/* SPI3  Base Address 									*/

#define USART2_BASE_ADDR		(APB1_BASE_ADDR + 0x00004400UL)				/* USART2  Base Address 								*/
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x00004800UL)				/* USART3  Base Address 								*/

#define UART4_BASE_ADDR			(APB1_BASE_ADDR + 0x00004C00UL)				/* UART4  Base Address 									*/
#define UART5_BASE_ADDR			(APB1_BASE_ADDR + 0x00005000UL)				/* UART5  Base Address 									*/

#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x00005400UL)				/* I2C1  Base Address 									*/
#define I2C2_BASE_ADDR			(APB1_BASE_ADDR + 0x00005800UL)				/* I2C2  Base Address 									*/
#define I2C3_BASE_ADDR			(APB1_BASE_ADDR + 0x00005C00UL)				/* I2C3  Base Address 									*/


/*
 * APB2 Peripheral Base Addresses
 *
 */

#define TIM1_BASE_ADDR			(APB2_BASE_ADDR + 0x00000000UL)				/* Timer1 Base Address 									*/
#define TIM8_BASE_ADDR			(APB2_BASE_ADDR + 0x00000400UL)				/* Timer8 Base Address 									*/

#define USART1_BASE_ADDR		(APB2_BASE_ADDR + 0x00001000UL)				/* USART1 Base Address 									*/
#define USART6_BASE_ADDR		(APB2_BASE_ADDR + 0x00001400UL)				/* USART6 Base Address 									*/

#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x00003000UL)				/* SPI1 Base Address 									*/
#define SPI4_BASE_ADDR			(APB2_BASE_ADDR + 0x00003400UL)				/* SPI4 Base Address 									*/

#define SYSCFG_BASE_ADDR		(APB2_BASE_ADDR + 0x00003800UL)				/* SYSCFG Register Base Address 						*/
#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x00003C00UL)				/* EXTI Base Address 									*/


/*
 * AHB1 Peripheral Base Addresses
 *
 */

#define GPIOA_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000000UL)				/* GPIOA Base Address 									*/
#define GPIOB_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000400UL)				/* GPIOB Base Address 									*/
#define GPIOC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000800UL)				/* GPIOC Base Address 									*/
#define GPIOD_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000C00UL)				/* GPIOD Base Address 									*/
#define GPIOE_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001000UL)				/* GPIOE Base Address 									*/
#define GPIOF_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001400UL)				/* GPIOF Base Address 									*/
#define GPIOG_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001800UL)				/* GPIOG Base Address 									*/
#define GPIOH_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001C00UL)				/* GPIOH Base Address 									*/
#define GPIOI_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002000UL)				/* GPIOI Base Address 									*/
#define GPIOJ_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002400UL)				/* GPIOJ Base Address 									*/
#define GPIOK_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002800UL)				/* GPIOK Base Address 									*/

#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00003800UL)				/* RCC Base Address 									*/


/*
 * Peripheral Structure Definitions
 *
 */

typedef struct
{
	__IO uint32_t MODER;			/*!<GPIO port mode register 						Address Offset = 0x0000  >!*/
	__IO uint32_t OTYPER;			/*!<GPIO port output type register 					Address Offset = 0x0004  >!*/
	__IO uint32_t OSPEEDR;			/*!<GPIO port output speed register 				Address Offset = 0x0008  >!*/
	__IO uint32_t PUPDR;			/*!<GPIO port pull-up/pull-down register		    Address Offset = 0x000C  >!*/
	__IO uint32_t IDR;				/*!<GPIO port input data register 					Address Offset = 0x0010  >!*/
	__IO uint32_t ODR;				/*!<GPIO port output data register 					Address Offset = 0x0014  >!*/
	__IO uint32_t BSRR;				/*!<GPIO port bit set/reset register 				Address Offset = 0x0018  >!*/
	__IO uint32_t LCKR;				/*!<GPIO port configuration lock register 			Address Offset = 0x001C  >!*/
	__IO uint32_t AFR[2];			/*!<GPIO alternate function low and high register 	Address Offset = 0x0020  >!*/

}GPIO_TypeDef_t;


typedef struct
{
	__IO uint32_t CR;				/*!<RCC clock control register 										Address Offset = 0x0000  >!*/
	__IO uint32_t PLLCFGR;			/*!<RCC PLL configuration register									Address Offset = 0x0004  >!*/
	__IO uint32_t CFGR;				/*!<RCC PLL configuration register									Address Offset = 0x0008  >!*/
	__IO uint32_t CIR;				/*!<RCC clock interrupt register									Address Offset = 0x000C  >!*/
	__IO uint32_t AHB1RSTR;			/*!<RCC AHB1 peripheral reset register								Address Offset = 0x0010  >!*/
	__IO uint32_t AHB2RSTR;			/*!<RCC AHB2 peripheral reset register								Address Offset = 0x0014  >!*/
	__IO uint32_t AHB3RSTR;			/*!<RCC AHB3 peripheral reset register								Address Offset = 0x0018  >!*/
	__IO uint32_t RESERVED0;		/*!<RESERVED			 											Address Offset = 0x001C  >!*/
	__IO uint32_t APB1RSTR;			/*!<RCC APB1 peripheral reset register 								Address Offset = 0x0020  >!*/
	__IO uint32_t APB2RSTR;			/*!<RCC APB2 peripheral reset register 								Address Offset = 0x0024  >!*/
	__IO uint32_t RESERVED1;		/*!<RESERVED														Address Offset = 0x0028  >!*/
	__IO uint32_t RESERVED2;		/*!<RESERVED 														Address Offset = 0x002C  >!*/
	__IO uint32_t AHB1ENR;			/*!<RCC AHB1 peripheral clock register  							Address Offset = 0x0030  >!*/
	__IO uint32_t AHB2ENR;			/*!<RCC AHB2 peripheral enable clock register  						Address Offset = 0x0034  >!*/
	__IO uint32_t AHB3ENR;			/*!<RCC AHB3 peripheral enable clock register  						Address Offset = 0x0038  >!*/
	__IO uint32_t RESERVED3;		/*!<RESERVED 			 											Address Offset = 0x003C  >!*/
	__IO uint32_t APB1ENR;			/*!<RCC APB1 peripheral clock enable register 						Address Offset = 0x0040  >!*/
	__IO uint32_t APB2ENR;			/*!<RCC APB2 peripheral clock enable register						Address Offset = 0x0044  >!*/
	__IO uint32_t RESERVED4;		/*!<RESERVED 														Address Offset = 0x0048  >!*/
	__IO uint32_t RESERVED5;		/*!<RESERVED  														Address Offset = 0x004C  >!*/
	__IO uint32_t AHB1LPENR;		/*!<RCC AHB1 peripheral clock enable in low power mode register 	Address Offset = 0x0050  >!*/
	__IO uint32_t AHB2LPENR;		/*!<RCC AHB2 peripheral clock enable in low power mode register		Address Offset = 0x0054  >!*/
	__IO uint32_t AHB3LPENR;		/*!<RCC AHB3 peripheral clock enable in low power mode register		Address Offset = 0x0058  >!*/
	__IO uint32_t RESERVED6;		/*!<RESERVED  														Address Offset = 0x005C  >!*/
	__IO uint32_t APB1LPENR;		/*!<RCC APB1 peripheral clock enable in low power mode register		Address Offset = 0x0060  >!*/
	__IO uint32_t APB2LPENR;		/*!<RCC APB2 peripheral clock enable in low power mode register 	Address Offset = 0x0064  >!*/
	__IO uint32_t RESERVED7;		/*!<RESERVED 														Address Offset = 0x0068  >!*/
	__IO uint32_t RESERVED8;		/*!<RESERVED  														Address Offset = 0x006C  >!*/
	__IO uint32_t BDCR;				/*!<RCC Backup domain control register								Address Offset = 0x0070  >!*/
	__IO uint32_t CSR;				/*!<RCC clock control & status register 							Address Offset = 0x0074  >!*/
	__IO uint32_t RESERVED9;		/*!<RESERVED														Address Offset = 0x0078  >!*/
	__IO uint32_t RESERVED10;		/*!<RESERVED														Address Offset = 0x007C  >!*/
	__IO uint32_t SSCGR;			/*!<RCC spread spectrum clock generation register 					Address Offset = 0x0080  >!*/
	__IO uint32_t PLLI2SCFGR;		/*!<RCC PLLI2S configuration register 								Address Offset = 0x0084  >!*/
	__IO uint32_t PLLSAICFGR;		/*!<RCC PLL configuration register 									Address Offset = 0x0088  >!*/
	__IO uint32_t DCKCFGR;			/*!<RCC Dedicated Clock Configuration Register 						Address Offset = 0x008C  >!*/

}RCC_TypeDef_t;

typedef struct
{
	__IO uint32_t MEMRMP;			/*!< SYSCFG memory remap register      								Address Offset = 0x0000 >*/
	__IO uint32_t PMC;				/*!< SYSCFG peripheral mode configuration register					Address Offset = 0x0004 >*/
	__IO uint32_t EXTI_CR[4];		/*!< SYSCFG external interrupt configuration register				Address Offset = 0x0008 >*/
	__IO uint32_t CMPCR;			/*!< Compensation cell control register								Address Offset = 0x0020 >*/

}SYSCFG_TypeDef_t;

typedef struct
{
	__IO uint32_t IMR;				/*!< Interrupt mask register      							 		Address Offset = 0x0000 >*/
	__IO uint32_t EMR;				/*!< Event mask register      										Address Offset = 0x0004 >*/
	__IO uint32_t RTSR;				/*!< Rising trigger selection register      						Address Offset = 0x0008 >*/
	__IO uint32_t FTSR;				/*!< Falling trigger selection register      						Address Offset = 0x000C >*/
	__IO uint32_t SWIER;			/*!< Software interrupt event register      						Address Offset = 0x0010 >*/
	__IO uint32_t PR;				/*!< Pending register      											Address Offset = 0x0014 >*/

}EXTI_TypeDef_t;


typedef struct
{
	__IO uint32_t SPI_CR1;			/*!< SPI control register 1	      							 		Address Offset = 0x0000 >*/
	__IO uint32_t SPI_CR2;			/*!< SPI control register 2	      							 		Address Offset = 0x0004 >*/
	__IO uint32_t SPI_SR;			/*!< SPI status register	      							 		Address Offset = 0x0008 >*/
	__IO uint32_t SPI_DR;			/*!< SPI data register		      							 		Address Offset = 0x000C >*/
	__IO uint32_t SPI_CRCPR;		/*!< SPI CRC polynomial register   							 		Address Offset = 0x0010 >*/
	__IO uint32_t SPI_RXCRCR;		/*!< SPI RX CRC register	      							 		Address Offset = 0x0014 >*/
	__IO uint32_t SPI_TXCRCR;		/*!< SPI TX CRC register	      							 		Address Offset = 0x0018 >*/
	__IO uint32_t I2SCFGR;			/*!< SPI_I2S configuration register							 		Address Offset = 0x001C >*/
	__IO uint32_t I2SPR;			/*!< SPI_I2S prescaler register    							 		Address Offset = 0x0020 >*/

}SPI_TypeDef_t;


typedef struct
{
	__IO uint32_t SR;				/*!< USART Status register 	      							 		Address Offset = 0x0000 >*/
	__IO uint32_t DR;				/*!< USART Data register 	        							 	Address Offset = 0x0004 >*/
	__IO uint32_t BRR;				/*!< USART Baudrate register	      								Address Offset = 0x0008 >*/
	__IO uint32_t CR1;				/*!< USART control register1	      						 		Address Offset = 0x000C >*/
	__IO uint32_t CR2;				/*!< USART control register2	      						 		Address Offset = 0x0010 >*/
	__IO uint32_t CR3;				/*!< USART control register3	      						 		Address Offset = 0x0014 >*/
	__IO uint32_t GTPR;				/*!< USART Guard time and prescelar 						 		Address Offset = 0x0018 >*/

}USART_TypeDef_t;


typedef struct
{
	__IO uint32_t CR1;				/*!< I2C Control register 1 	      						 		Address Offset = 0x0000 >*/
	__IO uint32_t CR2;				/*!< I2C Control register 2 	      						 		Address Offset = 0x0004 >*/
	__IO uint32_t OAR1;				/*!< I2C Own address register 1       						 		Address Offset = 0x0008 >*/
	__IO uint32_t OAR2;				/*!< I2C Own address register 2	      						 		Address Offset = 0x000C >*/
	__IO uint32_t DR;				/*!< I2C Data register		 	      						 		Address Offset = 0x0010 >*/
	__IO uint32_t SR1;				/*!< I2C Status register 1 		      						 		Address Offset = 0x0014 >*/
	__IO uint32_t SR2;				/*!< I2C Status register 2	 	      						 		Address Offset = 0x0018 >*/
	__IO uint32_t CCR;				/*!< I2C Clock control register       						 		Address Offset = 0x001C >*/
	__IO uint32_t TRISE;			/*!< I2C TRISE register		 	      						 		Address Offset = 0x0020 >*/
	__IO uint32_t FLTR;				/*!< I2C FLTR register		 	      						 		Address Offset = 0x0024 >*/

}I2C_TypeDef_t;



#define GPIOA							((GPIO_TypeDef_t*)(GPIOA_BASE_ADDR))
#define GPIOB							((GPIO_TypeDef_t*)(GPIOB_BASE_ADDR))
#define GPIOC							((GPIO_TypeDef_t*)(GPIOC_BASE_ADDR))
#define GPIOD							((GPIO_TypeDef_t*)(GPIOD_BASE_ADDR))
#define GPIOE							((GPIO_TypeDef_t*)(GPIOE_BASE_ADDR))
#define GPIOF							((GPIO_TypeDef_t*)(GPIOF_BASE_ADDR))
#define GPIOG							((GPIO_TypeDef_t*)(GPIOG_BASE_ADDR))
#define GPIOH							((GPIO_TypeDef_t*)(GPIOH_BASE_ADDR))
#define GPIOI							((GPIO_TypeDef_t*)(GPIOI_BASE_ADDR))
#define GPIOJ							((GPIO_TypeDef_t*)(GPIOJ_BASE_ADDR))
#define GPIOK							((GPIO_TypeDef_t*)(GPIOK_BASE_ADDR))

#define RCC								((RCC_TypeDef_t* )(RCC_BASE_ADDR)  )

#define SYSCFG							((SYSCFG_TypeDef_t*)(SYSCFG_BASE_ADDR))

#define EXTI							((EXTI_TypeDef_t*)(EXTI_BASE_ADDR))

#define SPI1							((SPI_TypeDef_t*)(SPI1_BASE_ADDR))
#define SPI2							((SPI_TypeDef_t*)(SPI2_BASE_ADDR))
#define SPI3							((SPI_TypeDef_t*)(SPI3_BASE_ADDR))
#define SPI4							((SPI_TypeDef_t*)(SPI4_BASE_ADDR))

#define USART2							((USART_TypeDef_t*)(USART2_BASE_ADDR))
#define USART3							((USART_TypeDef_t*)(USART3_BASE_ADDR))
#define UART4							((USART_TypeDef_t*)(UART4_BASE_ADDR))
#define UART5							((USART_TypeDef_t*)(UART5_BASE_ADDR))

#define USART1							((USART_TypeDef_t*)(USART1_BASE_ADDR))
#define USART6							((USART_TypeDef_t*)(USART6_BASE_ADDR))

#define I2C1							((I2C_TypeDef_t*)(I2C1_BASE_ADDR))
#define I2C2							((I2C_TypeDef_t*)(I2C2_BASE_ADDR))
#define I2C3							((I2C_TypeDef_t*)(I2C3_BASE_ADDR))



/*
 *	GPIO Enable Macros
 *
 */

#define RCC_AHB1ENR_GPIOAEN_Pos			(0UL)										//RCC AHB1ENR register GPIOAEN bit position
#define RCC_AHB1ENR_GPIOAEN_Msk			(0x1<<RCC_AHB1ENR_GPIOAEN_Pos)				//RCC AHB1ENR register GPIOAEN bit mask
#define RCC_AHB1ENR_GPIOAEN				RCC_AHB1ENR_GPIOAEN_Msk						//RCC AHB1ENR register GPIOAEN bit macro

#define RCC_AHB1ENR_GPIOBEN_Pos			(1UL)										//RCC AHB1ENR register GPIOBEN bit position
#define RCC_AHB1ENR_GPIOBEN_Msk			(0x1<<RCC_AHB1ENR_GPIOBEN_Pos)				//RCC AHB1ENR register GPIOBEN bit mask
#define RCC_AHB1ENR_GPIOBEN				RCC_AHB1ENR_GPIOBEN_Msk						//RCC AHB1ENR register GPIOBEN bit macro

#define RCC_AHB1ENR_GPIOCEN_Pos			(2UL)										//RCC AHB1ENR register GPIOCEN bit position
#define RCC_AHB1ENR_GPIOCEN_Msk			(0x1<<RCC_AHB1ENR_GPIOCEN_Pos)				//RCC AHB1ENR register GPIOCEN bit mask
#define RCC_AHB1ENR_GPIOCEN				RCC_AHB1ENR_GPIOCEN_Msk						//RCC AHB1ENR register GPIOCEN bit macro

#define RCC_AHB1ENR_GPIODEN_Pos			(3UL)										//RCC AHB1ENR register GPIODEN bit position
#define RCC_AHB1ENR_GPIODEN_Msk			(0x1<<RCC_AHB1ENR_GPIODEN_Pos)				//RCC AHB1ENR register GPIODEN bit mask
#define RCC_AHB1ENR_GPIODEN				RCC_AHB1ENR_GPIODEN_Msk						//RCC AHB1ENR register GPIODEN bit macro

#define RCC_AHB1ENR_GPIOEEN_Pos			(4UL)										//RCC AHB1ENR register GPIODEN bit position
#define RCC_AHB1ENR_GPIOEEN_Msk			(0x1<<RCC_AHB1ENR_GPIOEEN_Pos)				//RCC AHB1ENR register GPIODEN bit mask
#define RCC_AHB1ENR_GPIOEEN				RCC_AHB1ENR_GPIOEEN_Msk						//RCC AHB1ENR register GPIODEN bit macro

#define RCC_APB2ENR_SYSCFG_Pos			(14UL)										//RCC APB2ENR register SYSCFG bit position
#define RCC_APB2ENR_SYSCFG_Msk			(0x1<<RCC_APB2ENR_SYSCFG_Pos)				//RCC APB2ENR register SYSCFG bit mask
#define RCC_APB2ENR_SYSCFG				RCC_APB2ENR_SYSCFG_Msk						//RCC APB2ENR register SYSCFG bit macro

#define RCC_APB2ENR_SPI1_Pos			(12UL)										//RCC APB2ENR register SPI1   bit position
#define RCC_APB2ENR_SPI1_Msk			(0x1<<RCC_APB2ENR_SPI1_Pos)					//RCC APB2ENR register SPI1   bit mask
#define RCC_APB2ENR_SPI1				RCC_APB2ENR_SPI1_Msk						//RCC APB2ENR register SPI1   bit macro

#define RCC_APB2ENR_SPI4_Pos			(13UL)										//RCC APB2ENR register SPI4  bit position
#define RCC_APB2ENR_SPI4_Msk			(0x1<<RCC_APB2ENR_SPI4_Pos)					//RCC APB2ENR register SPI4  bit mask
#define RCC_APB2ENR_SPI4				RCC_APB2ENR_SPI4_Msk						//RCC APB2ENR register SPI4  bit macro

#define RCC_APB1ENR_SPI2_Pos			(14UL)										//RCC APB1ENR register SPI2  bit position
#define RCC_APB1ENR_SPI2_Msk			(0x1<<RCC_APB1ENR_SPI2_Pos)					//RCC APB1ENR register SPI2  bit mask
#define RCC_APB1ENR_SPI2				RCC_APB1ENR_SPI2_Msk						//RCC APB1ENR register SPI2  bit macro

#define RCC_APB1ENR_SPI3_Pos			(15UL)										//RCC APB1ENR register SPI3  bit position
#define RCC_APB1ENR_SPI3_Msk			(0x1<<RCC_APB1ENR_SPI3_Pos)					//RCC APB1ENR register SPI3  bit mask
#define RCC_APB1ENR_SPI3				RCC_APB1ENR_SPI3_Msk						//RCC APB1ENR register SPI3  bit macro

#define RCC_APB1ENR_USART2_Pos			(17UL)										//RCC APB1ENR register USART2  bit position
#define RCC_APB1ENR_USART2_Msk			(0x1<<RCC_APB1ENR_USART2_Pos)				//RCC APB1ENR register USART2  bit mask
#define RCC_APB1ENR_USART2				RCC_APB1ENR_USART2_Msk						//RCC APB1ENR register USART2  bit macro

#define RCC_APB1ENR_USART3_Pos			(18UL)										//RCC APB1ENR register USART3  bit position
#define RCC_APB1ENR_USART3_Msk			(0x1<<RCC_APB1ENR_USART3_Pos)				//RCC APB1ENR register USART3  bit mask
#define RCC_APB1ENR_USART3				RCC_APB1ENR_USART3_Msk						//RCC APB1ENR register USART3  bit macro

#define RCC_APB1ENR_I2C1_Pos			(21UL)										//RCC APB1ENR register I2C1  bit position
#define RCC_APB1ENR_I2C1_Msk			(0x1<<RCC_APB1ENR_I2C1_Pos)					//RCC APB1ENR register I2C1  bit position
#define RCC_APB1ENR_I2C1					RCC_APB1ENR_I2C1_Msk						//RCC APB1ENR register I2C1  bit position



#define SPI_SR_TxE						(1U)										// SPI SR register TxE Flag Register bit number
#define SPI_SR_Busy						(7U)									    // SPI SR register Busy Flag Register bit number
#define SPI_SR_RxNE						(0U)										// SPI SR register RxNE Flag Register bit number


#define SPI_CR1_SPE						(6U)										// SPI CR1 register SPI Enable bit number
#define SPI_CR1_DFF						(11U)										// SPI CR1 register DFF Format bit number

#define SPI_CR2_TXEIE					(7U)										// SPI CR2 register SPI TXEIE bit number
#define SPI_CR2_RXNEIE					(6U)										// SPI CR2 register SPI RXNEIE bit number

#define USART_CR1_UE					(13U)
#define USART_CR1_TxEIE					(7U)
#define USART_CR1_RxNEIE				(5U)
#define USART_CR2_STOP					(12U)
#define USART_SR_Txe					(7U)
#define USART_SR_TC						(6U)
#define USART_SR_RxNE					(5U)

#define I2C_CR1_PE						(0U)										//Peripheral Enable


/*
 *	SPI Flag Macros
 *
 */


#define SPI_FLAG_TxE					(0x1U << SPI_SR_TxE)
#define SPI_FLAG_Busy					(0x1U << SPI_SR_Busy)
#define SPI_FLAG_RxNE					(0x1U << SPI_SR_Busy)

#define USART_Flag_Txe					(0x1U << USART_SR_Txe)
#define USART_Flag_TC					(0x1U << USART_SR_TC)
#define USART_Flag_RxNE					(0x1U << USART_SR_RxNE)




#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"
#include "USART.h"
#include "I2C.h"

#endif /* INC_STM32F439XX_H_ */
