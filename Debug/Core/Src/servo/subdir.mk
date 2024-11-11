################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/servo/servo.c 

OBJS += \
./Core/Src/servo/servo.o 

C_DEPS += \
./Core/Src/servo/servo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/servo/%.o Core/Src/servo/%.su Core/Src/servo/%.cyclo: ../Core/Src/servo/%.c Core/Src/servo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L152xE -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-servo

clean-Core-2f-Src-2f-servo:
	-$(RM) ./Core/Src/servo/servo.cyclo ./Core/Src/servo/servo.d ./Core/Src/servo/servo.o ./Core/Src/servo/servo.su

.PHONY: clean-Core-2f-Src-2f-servo

