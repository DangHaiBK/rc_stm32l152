#ifndef __UTILS_H
#define __UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "tim.h"

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

//extern TIM_HandleTypeDef htim3;

//__STATIC_INLINE void DWT_Init(void)
//{
//	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
//	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
//}
//
//__STATIC_INLINE uint32_t micros(void){
//	return  DWT->CYCCNT / (SystemCoreClock / 1000000U);
//}

__STATIC_INLINE long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void yield(void);
uint32_t micros(void);
void delay(uint32_t ms);
void analogWrite(uint8_t value);
//long map(long x, long in_min, long in_max, long out_min, long out_max);

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_H */
