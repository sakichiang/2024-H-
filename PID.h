#ifndef __PID_H__
#define __PID_H__

#include "board.h"

#define int16 int16_t

typedef struct 
{
    float SumError;  //����ۻ�

    float Kp;      //����ϵ��
    float Ki;      //����ϵ��
    float Kd;      //΢��ϵ��
	
    float LastError;  //��һ�����
    float LLastError; //���ϴ����
}PID;

//�ṹ���������
extern PID TurnPID;       //����
extern PID SpeedPID;      //�ٶȻ�
extern PID Turn_NeiPID;

//��������
void IncPIDInit(PID *sptr);
int16 IncPIDCalc(PID *sptr,int16 Setpoint,int16 Turepoint);//����ʽPID����
int16 Dynamic_pid(PID *sptr, int16 Set_value,int16 real_value);
int16 position_pid(PID *sptr,int16 Set_value,int16 real_value);
void Set_PWM(int pwma,int pwmb);

#endif
