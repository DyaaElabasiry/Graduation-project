################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/01-MCAL/02-GPIO/GPIO_program.c 

OBJS += \
./Src/01-MCAL/02-GPIO/GPIO_program.o 

C_DEPS += \
./Src/01-MCAL/02-GPIO/GPIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/01-MCAL/02-GPIO/%.o Src/01-MCAL/02-GPIO/%.su: ../Src/01-MCAL/02-GPIO/%.c Src/01-MCAL/02-GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-01-2d-MCAL-2f-02-2d-GPIO

clean-Src-2f-01-2d-MCAL-2f-02-2d-GPIO:
	-$(RM) ./Src/01-MCAL/02-GPIO/GPIO_program.d ./Src/01-MCAL/02-GPIO/GPIO_program.o ./Src/01-MCAL/02-GPIO/GPIO_program.su

.PHONY: clean-Src-2f-01-2d-MCAL-2f-02-2d-GPIO

