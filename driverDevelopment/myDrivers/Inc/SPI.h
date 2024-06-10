
#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f439xx.h"

typedef enum
{
	SPI_BUS_FREE = 0x0U,
	SPI_BUS_BUSY_TX = 0x1U,
	SPI_BUS_BUSY_RX = 0x2U

}SPI_BusStatus_t;



/*
 * @def_group SPI_BaudRates
 *
 */

#define SPI_BAUDRATE_DIV2			((uint32_t)(0x00000000))
#define SPI_BAUDRATE_DIV4			((uint32_t)(0x00000008))
#define SPI_BAUDRATE_DIV8			((uint32_t)(0x00000010))
#define SPI_BAUDRATE_DIV16			((uint32_t)(0x00000018))
#define SPI_BAUDRATE_DIV32			((uint32_t)(0x00000020))
#define SPI_BAUDRATE_DIV64			((uint32_t)(0x00000028))
#define SPI_BAUDRATE_DIV128			((uint32_t)(0x00000030))
#define SPI_BAUDRATE_DIV256			((uint32_t)(0x00000038))


/*
 * @def_group SPI_CPHA
 */

#define SPI_CPHA_FIRST_EDGE			((uint32_t)(0x00000))
#define SPI_CPHA_SECOND_EDGE		((uint32_t)(0x00001))


/*
 * @def_group SPI_CPOL
 */

#define SPI_CPOL_LOW				((uint32_t)(0x00000))
#define SPI_CPOL_HIGH				((uint32_t)(0x00002))


/*
 *
 * @def_group SPI_DFF_Format
 */

#define SPI_DFF_8BITS				((uint32_t)(0x000000))
#define SPI_DFF_16BITS				((uint32_t)(0x000800))


/*
 *
 *  @def_group SPI_Mode
 */

#define SPI_MASTER_MODE				((uint32_t)(0x000004))
#define SPI_SLAVE_MODE				((uint32_t)(0x000000))

/*
 *
 * @def_group SPI_FF_Format
 */

#define SPI_FRAMEFORMAT_MSB			((uint32_t)(0x000000))
#define SPI_FRAMEFORMAT_LSB			((uint32_t)(0x000080))

/*
 *
 * @def_group SPI_BUS_Config
 */
#define SPI_BUS_FullDuplex			((uint32_t)(0x000000))
#define SPI_BUS_ReceiveOnly			((uint32_t)(0x000400))
#define SPI_BUS_HalfDuplex_T		((uint32_t)(0x00C000))
#define SPI_BUS_HalfDuplex_R		((uint32_t)(0x008000))


/*
 * @def_group SPI_SSM_Cmd
 *
 */
#define SPI_SSM_DISABLE				((uint32_t)(0x000000))
#define SPI_SSM_ENABLE				((uint32_t)(0x000300))


typedef enum
{
	SPI_FLAG_RESET = 0x0,
	SPI_FLAG_SET = !SPI_FLAG_RESET

}SPI_FlagStatus_t;



typedef struct
{
	uint32_t Mode;						/*!< Mode Values for SPI @def_group SPI_Mode 		  		*/
	uint32_t CPHA;						/*!< CPHA Values for SPI @def_group SPI_CPHA 		  		*/
	uint32_t CPOL;						/*!< CPOL Values for SPI @def_group SPI_CPOL 		  		*/
	uint32_t Baudrate;					/*!< BaudRate Values for SPI @def_group SPI_BaudRates 		*/
	uint32_t SSM_Cmd;					/*!< Software Slave for SPI @def_group SPI_SSM_Cmd		 	*/
	uint32_t FrameFormat;				/*!< Frame Format Values for SPI @def_group SPI_FF_Format	*/
	uint32_t DFF_Format;				/*!< DFF Format Values for SPI @def_group SPI_DFF_Format 	*/
	uint32_t BusConfig;					/*!< Bus CONFIG Values for SPI @def_group SPI_BUS_Config 	*/

}SPI_InitTypeDef_t;


typedef struct __SPI_HandleTypeDef_t
{
	SPI_TypeDef_t * Instance;
	SPI_InitTypeDef_t Init;
	uint8_t *pTxDataAddr;
	uint16_t TxDataSize;
	uint8_t busStateTx;
	void(*TxISRFunction)(struct __SPI_HandleTypeDef_t *SPI_Handle);
	uint8_t busStateRx;
	uint8_t * pRxDataAddr;
	uint16_t RxDataSize;
	void(*RxISRFunction)(struct __SPI_HandleTypeDef_t *SPI_Handle);

}SPI_HandleTypeDef_t;





void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle);
void SPI_Activate(SPI_HandleTypeDef_t *SPI_Handle , FunctionalState_t StateOfSPI);
void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle , uint8_t *pData , uint16_t sizeOfData);
void SPI_ReceiveData(SPI_HandleTypeDef_t *SPI_Handle , uint8_t * pBuffer , uint16_t sizeOfData);
SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *SPI_Handle , uint16_t SPI_Flag);
void SPI_TransmitData_IT(SPI_HandleTypeDef_t *SPI_Handle , uint8_t *pData , uint16_t sizeOfData);
void SPI_ReceiveData_IT(SPI_HandleTypeDef_t *SPI_Handle , uint8_t * pBuffer , uint16_t sizeOfData);
void SPI_InterruptHandler(SPI_HandleTypeDef_t *SPI_Handle);






#endif /* INC_SPI_H_ */
