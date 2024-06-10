################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDrivers/Src/EXTI.c \
../myDrivers/Src/GPIO.c \
../myDrivers/Src/I2C.c \
../myDrivers/Src/RCC.c \
../myDrivers/Src/SPI.c \
../myDrivers/Src/USART.c 

OBJS += \
./myDrivers/Src/EXTI.o \
./myDrivers/Src/GPIO.o \
./myDrivers/Src/I2C.o \
./myDrivers/Src/RCC.o \
./myDrivers/Src/SPI.o \
./myDrivers/Src/USART.o 

C_DEPS += \
./myDrivers/Src/EXTI.d \
./myDrivers/Src/GPIO.d \
./myDrivers/Src/I2C.d \
./myDrivers/Src/RCC.d \
./myDrivers/Src/SPI.d \
./myDrivers/Src/USART.d 


# Each subdirectory must supply rules for building sources it contributes
myDrivers/Src/%.o myDrivers/Src/%.su myDrivers/Src/%.cyclo: ../myDrivers/Src/%.c myDrivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F439ZITx -DNUCLEO_F439ZI -c -I../Inc -I"C:/Users/omer/workspace_stm/driverDevelopment/myDrivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-myDrivers-2f-Src

clean-myDrivers-2f-Src:
	-$(RM) ./myDrivers/Src/EXTI.cyclo ./myDrivers/Src/EXTI.d ./myDrivers/Src/EXTI.o ./myDrivers/Src/EXTI.su ./myDrivers/Src/GPIO.cyclo ./myDrivers/Src/GPIO.d ./myDrivers/Src/GPIO.o ./myDrivers/Src/GPIO.su ./myDrivers/Src/I2C.cyclo ./myDrivers/Src/I2C.d ./myDrivers/Src/I2C.o ./myDrivers/Src/I2C.su ./myDrivers/Src/RCC.cyclo ./myDrivers/Src/RCC.d ./myDrivers/Src/RCC.o ./myDrivers/Src/RCC.su ./myDrivers/Src/SPI.cyclo ./myDrivers/Src/SPI.d ./myDrivers/Src/SPI.o ./myDrivers/Src/SPI.su ./myDrivers/Src/USART.cyclo ./myDrivers/Src/USART.d ./myDrivers/Src/USART.o ./myDrivers/Src/USART.su

.PHONY: clean-myDrivers-2f-Src

