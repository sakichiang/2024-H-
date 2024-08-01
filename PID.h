#ifndef __PID_H__
#define __PID_H__

#include "board.h"

#define int16 int16_t

typedef struct 
{
    float SumError;  //误差累积

    float Kp;      //比例系数
    float Ki;      //积分系数
    float Kd;      //微分系数
	
    float LastError;  //上一次误差
    float LLastError; //上上次误差
}PID;

//结构体变量申明
extern PID TurnPID;       //方向环
extern PID SpeedPID;      //速度环
extern PID Turn_NeiPID;

//函数声明
void IncPIDInit(PID *sptr);
int16 IncPIDCalc(PID *sptr,int16 Setpoint,int16 Turepoint);//增量式PID控制
int16 Dynamic_pid(PID *sptr, int16 Set_value,int16 real_value);
int16 position_pid(PID *sptr,int16 Set_value,int16 real_value);
void Set_PWM(int pwma,int pwmb);

#endif
