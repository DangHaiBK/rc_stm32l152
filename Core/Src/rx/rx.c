#include "rx.h"

volatile bool rx_new_pulse[] = {false, false, false, false, false, false};
volatile unsigned long rx_pulse_begin[] = {0, 0, 0, 0, 0, 0};
volatile unsigned long rx_channel_width[] = {0, 0, 0, 0, 0, 0};

void RX_ReadRaw(uint8_t state, uint8_t channel)
{
	if (state == RX_STATE_ACTIVE)
	{
		rx_pulse_begin[channel] = micros();
	}
	else
	{
		rx_channel_width[channel] = micros() - rx_pulse_begin[channel];
		rx_new_pulse[channel] = true;
	}
}

static unsigned long RX_ReadPwm(uint8_t channel)
{
    rx_new_pulse[channel] = false;
    return rx_channel_width[channel];
}

void RX_ReadPulse(uint8_t channel, uint8_t *direct, uint16_t *val)
{
    /* Get PWM receiver value */
    static unsigned long prevValue[] = {0, 0, 0, 0, 0, 0};
    static unsigned long ulValue = 0;
    unsigned long curValue = RX_ReadPwm(channel);

    if ((curValue == 0) && (prevValue[channel] == 0))
    {
        *direct = RECEIVER_STICK_LOSS_OR_FAIL;
        *val = RECEIVER_PWM_LOSS_OR_FAIL;
    }
    else
    {
        if (curValue != 0)
        {
            ulValue = curValue;
        }
        if ((prevValue[channel] != 0) && (curValue == 0))
        {
            ulValue = prevValue[channel];
        }

        /* Hold the value of the ulValue, determine the direction of the stick based on value PWM at the neutral position */
        *val = ulValue;
        if (ulValue > RECEIVER_PWM_NEUTRAL)
        {
            *direct = RECEIVER_STICK_INCREASING;
        }
        else if (ulValue < RECEIVER_PWM_NEUTRAL)
        {
            *direct = RECEIVER_STICK_DECREASING;
        }

        /* ulValue is out of range, val > 2000 + Error_rate or val < 1000 - Error_rate */
        if ((ulValue > RECEIVER_PWM_MAX + RECEIVER_ERROR_RATE) || (ulValue < RECEIVER_PWM_MIN - RECEIVER_ERROR_RATE))
        {
            *direct = RECEIVER_STICK_LOSS_OR_FAIL;
            *val = RECEIVER_PWM_LOSS_OR_FAIL;
        }

        /* ulValue is in range of [2000 - Error_rate; 2000 + Error_rate] */
        else if ((ulValue <= RECEIVER_PWM_MAX + RECEIVER_ERROR_RATE) && (ulValue >= RECEIVER_PWM_MAX - RECEIVER_ERROR_RATE))
        {
            *direct = RECEIVER_STICK_INCREASING;
            *val = RECEIVER_PWM_MAX;
        }

        /* ulValue is in range of [1000 - Error_rate; 1000 + Error_rate] */
        else if ((ulValue <= RECEIVER_PWM_MIN + RECEIVER_ERROR_RATE) && (ulValue >= RECEIVER_PWM_MIN - RECEIVER_ERROR_RATE))
        {
            *direct = RECEIVER_STICK_DECREASING;
            *val = RECEIVER_PWM_MIN;
        }

        /* ulValue is in range of [1500 - Error_rate; 1500 + Error_rate] */
        else if ((ulValue <= RECEIVER_PWM_NEUTRAL + RECEIVER_ERROR_RATE) && (ulValue >= RECEIVER_PWM_NEUTRAL - RECEIVER_ERROR_RATE))
        {
            *direct = RECEIVER_STICK_MIDDLE;
            *val = RECEIVER_PWM_NEUTRAL;
        }
    }
    prevValue[channel] = curValue;
}
