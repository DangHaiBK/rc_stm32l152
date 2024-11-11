#include "main.h"
#include "../utils/utils.h"
#include <stdbool.h>

#define RX_STATE_ACTIVE                     1
#define RX_STATE_INACTIVE                   0

#define RX_MC6C_NUMBER_CHANNEL              6

#define RX_INPUT_MAP_CHANNEL_1_TO_NUMBER    0
#define RX_INPUT_MAP_CHANNEL_2_TO_NUMBER    1
#define RX_INPUT_MAP_CHANNEL_3_TO_NUMBER    2
#define RX_INPUT_MAP_CHANNEL_4_TO_NUMBER    3
#define RX_INPUT_MAP_CHANNEL_5_TO_NUMBER    4
#define RX_INPUT_MAP_CHANNEL_6_TO_NUMBER    5

#define RX_CHANNEL_1                        0
#define RX_CHANNEL_2                        1
#define RX_CHANNEL_3                        2
#define RX_CHANNEL_4                        3
#define RX_CHANNEL_5                        4
#define RX_CHANNEL_6                        5

#define RECEIVER_PWM_NEUTRAL                1500    /* Typical value */
#define RECEIVER_PWM_MAX                    2000    /* Typical value */
#define RECEIVER_PWM_MIN                    1000    /* Typical value */
#define RECEIVER_ERROR_RATE                 30      /* Typical value +- this value */
#define RECEIVER_FRESH_RATE                 100     /* [MS] Frame rate, typical 10 - 300 Hz */
#define RECEIVER_PWM_LOSS_OR_FAIL           255
#define RECEIVER_PWM_FAIL_COUNT             10

#define RECEIVER_STICK_MIDDLE               0
#define RECEIVER_STICK_INCREASING           1
#define RECEIVER_STICK_DECREASING           2
#define RECEIVER_STICK_LOSS_OR_FAIL         3

#define RX_QUEUE_LENGTH                     6
#define RX_QUEUE_NUMBER                     6

void RX_ReadRaw(uint8_t state, uint8_t channel);
void RX_ReadPulse(uint8_t channel, uint8_t *direct, uint16_t *val);
