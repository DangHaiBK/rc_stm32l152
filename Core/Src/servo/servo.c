#include "servo.h"

struct SERVO_Params
{
	uint8_t ServoCount;
	uint8_t ServoValidValue;
	int8_t min;
	int8_t max;
};

struct SERVO_Params params;

void SERVO_writeMicroseconds(int value)
{
	if (value < MIN_PULSE_WIDTH)
	{
		value = MIN_PULSE_WIDTH;
	}
	else if (value > MAX_PULSE_WIDTH)
	{
		value = MAX_PULSE_WIDTH;
	}
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, value);
}

void SERVO_write(int value)
{
	if (value < MIN_PULSE_WIDTH)
	{
		if (value < 0)
		{
			value = 0;
		}
		else if (value > 180)
		{
			value = 180;
		}
	}
	value = map(value, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
	SERVO_writeMicroseconds(value);
}

void SERVO_attach(uint8_t name_srv, int value)
{
	params.ServoCount ++;
	if (params.ServoCount < MAX_SERVOS)
	{
		SERVO_write(value);
		params.ServoValidValue = VALID_SERVO;
	}
	else
	{
		params.ServoValidValue = INVALID_SERVO;
	}
}
