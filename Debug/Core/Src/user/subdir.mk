################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/user/utils.c 

OBJS += \
./Core/Src/user/utils.o 

C_DEPS += \
./Core/Src/user/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/user/%.o Core/Src/user/%.su Core/Src/user/%.cyclo: ../Core/Src/user/%.c Core/Src/user/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L152xE -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-user

clean-Core-2f-Src-2f-user:
	-$(RM) ./Core/Src/user/utils.cyclo ./Core/Src/user/utils.d ./Core/Src/user/utils.o ./Core/Src/user/utils.su

.PHONY: clean-Core-2f-Src-2f-user

