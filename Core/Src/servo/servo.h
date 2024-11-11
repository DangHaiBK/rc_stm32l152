#ifndef __SERVO_H
#define __SERVO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tim.h"
#include "../utils/utils.h"

#define Servo_VERSION           2     // software version of this library

#define MIN_PULSE_WIDTH       544     // the shortest pulse sent to a servo
#define MAX_PULSE_WIDTH      2400     // the longest pulse sent to a servo
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define REFRESH_INTERVAL    20000     // minimum time to refresh servos in microseconds

#define SERVOS_PER_TIMER       12     // the maximum number of servos controlled by one timer
#define NBR_16TIMERS            1     // Number of timers used for servos
#define MAX_SERVOS   (NBR_16TIMERS  * SERVOS_PER_TIMER)

#define INVALID_SERVO         255     // flag indicating an invalid servo index
#define VALID_SERVO           1

void SERVO_attach(uint8_t name_srv, int value);
void SERVO_write(int value);
void SERVO_writeMicroseconds(int value);

#ifdef __cplusplus
}
#endif

#endif /* __SERVO_H */
