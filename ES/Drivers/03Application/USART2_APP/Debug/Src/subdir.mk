################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GPIO_program.c \
../Src/LED_program.c \
../Src/PORT_program.c \
../Src/RCC_program.c \
../Src/USART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/GPIO_program.o \
./Src/LED_program.o \
./Src/PORT_program.o \
./Src/RCC_program.o \
./Src/USART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/GPIO_program.d \
./Src/LED_program.d \
./Src/PORT_program.d \
./Src/RCC_program.d \
./Src/USART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/LED_program.d ./Src/LED_program.o ./Src/LED_program.su ./Src/PORT_program.d ./Src/PORT_program.o ./Src/PORT_program.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/USART_program.d ./Src/USART_program.o ./Src/USART_program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

