################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/02-HAL/03-MCP/MCP2515_Program.c 

OBJS += \
./Src/02-HAL/03-MCP/MCP2515_Program.o 

C_DEPS += \
./Src/02-HAL/03-MCP/MCP2515_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/02-HAL/03-MCP/%.o Src/02-HAL/03-MCP/%.su: ../Src/02-HAL/03-MCP/%.c Src/02-HAL/03-MCP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-02-2d-HAL-2f-03-2d-MCP

clean-Src-2f-02-2d-HAL-2f-03-2d-MCP:
	-$(RM) ./Src/02-HAL/03-MCP/MCP2515_Program.d ./Src/02-HAL/03-MCP/MCP2515_Program.o ./Src/02-HAL/03-MCP/MCP2515_Program.su

.PHONY: clean-Src-2f-02-2d-HAL-2f-03-2d-MCP

