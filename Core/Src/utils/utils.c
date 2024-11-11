#include "utils.h"

/**
 * Get micro-seconds function
 * Using the same function in STM32duino
 */
uint32_t micros(void)
{
	  uint32_t m0 = HAL_GetTick();
	  volatile uint32_t u0 = SysTick->VAL;
	  uint32_t m1 = HAL_GetTick();
	  volatile uint32_t u1 = SysTick->VAL;
	  const uint32_t tms = SysTick->LOAD + 1;

	  if (m1 != m0) {
	    return (m1 * 1000 + ((tms - u1) * 1000) / tms);
	  } else {
	    return (m0 * 1000 + ((tms - u0) * 1000) / tms);
	  }
}

/**
 * Support function to do delay time
 */
static void __empty()
{
  // Empty
}

void yield(void) __attribute__((weak, alias("__empty")));

/**
 * Get milli-seconds function
 */
static uint32_t getCurrentMillis(void)
{
  return HAL_GetTick();
}

/**
 * delay function
 * Using the same function in STM32duino
 * This function provides more exact delay time than HAL_Delay()
 */
void delay(uint32_t ms)
{
  if (ms != 0) {
    uint32_t start = getCurrentMillis();
    do {
      yield();
    } while (getCurrentMillis() - start < ms);
  }
}

//long map(long x, long in_min, long in_max, long out_min, long out_max)
//{
//  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
//}

/**
 * analogWrite function
 * Using the same function but different code in STM32duino
 * This function exports PWM to a dedicated pin
 * @value: [percentage] unit
 * @number: 2000 - period [us], 10 - (Prescaler/Fclk) [us]
 */
void analogWrite(uint8_t value)
{
	uint16_t val_tim = (value / 100) * 2000 * (1 / 10);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, val_tim);
}

