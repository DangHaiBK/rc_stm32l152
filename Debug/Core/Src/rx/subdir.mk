################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/rx/rx.c 

OBJS += \
./Core/Src/rx/rx.o 

C_DEPS += \
./Core/Src/rx/rx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/rx/%.o Core/Src/rx/%.su Core/Src/rx/%.cyclo: ../Core/Src/rx/%.c Core/Src/rx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L152xE -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-rx

clean-Core-2f-Src-2f-rx:
	-$(RM) ./Core/Src/rx/rx.cyclo ./Core/Src/rx/rx.d ./Core/Src/rx/rx.o ./Core/Src/rx/rx.su

.PHONY: clean-Core-2f-Src-2f-rx

