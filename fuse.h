#ifndef __FUSE_H__
#define __FUSE_H__

#include "board.h"

#define int16 int16_t

void PID_int(void);
void speed_pwm(void);
void angle_pid();
void turn_pid();
void speed_turn_out();
void swith_key(void);

#endif