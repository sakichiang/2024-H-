#include "PID.h"

/************************************************
��������IncPIDInit(PID *sptr)
��  �ܣ�PID������ʼ��
��  ����
����ֵ��void
************************************************/
void IncPIDInit(PID *sptr)
{
    sptr->SumError=0;
    sptr->LastError=0;
    sptr->LLastError=0;

    sptr->Kp=0;
    sptr->Ki=0;
    sptr->Kd=0;
}

/************************************************
��������position_pid(PID *sptr,int16 Setpoint,int16 Turepoint)
��  �ܣ�λ��ʽPID����
************************************************/
int err_angle=0;
int16 position_pid(PID *sptr,int16 Set_value,int16 real_value)
{
    int16 iError,dError;
    int16 output;
		uint8_t  i_ing=0;
	if(ABS(Set_value)>155){
		if(real_value<0){
			real_value=-real_value;
		}
		if(real_value>0){
			real_value=360-real_value;
		}
		Set_value=Set_value;
	}
  
    iError=Set_value-real_value;  //ƫ��
	
		if(ABS(iError)<40&&ABS(iError)>5)
		{
			i_ing = 1;
			sptr->SumError+=iError;            //����(����ʱ��ܶ�ʱ����һ�ײ�ִ���һ��΢�֣����ۼӴ������)
		}
		else	
		{
			i_ing = 0;
			sptr->SumError=0;            //����(����ʱ��ܶ�ʱ����һ�ײ�ִ���һ��΢�֣����ۼӴ������)
		}
		
		err_angle=iError;
//    sptr->SumError+=iError;            //����(����ʱ��ܶ�ʱ����һ�ײ�ִ���һ��΢�֣����ۼӴ������)
    dError=(int16)(iError-(sptr->LastError));     //΢��
    sptr->LastError=iError;
    if(sptr->SumError>3000) sptr->SumError=3000;   //�����޷�
    if(sptr->SumError<-3000) sptr->SumError=-3000;
    output=(int16)(sptr->Kp*iError  //������
          +(i_ing*(sptr->Ki*sptr->SumError))//������
          +sptr->Kd*dError);        //΢����
    return(output);
} 

/************************************************
��������IncPIDCalc(PID *sptr,int16 Setpoint,int16 Turepoint)
��  �ܣ�����ʽPID����
��  ����PID *sptr,int16 Setpoint,int16 Turepoint
����ֵ��int32 iIncpid
************************************************/
int16 IncPIDCalc(PID *sptr,int16 Setpoint,int16 Turepoint)
{
    int16 iError,iIncpid;
    //��ǰ���
    iError=Setpoint-Turepoint;      //ƫ��
	
    //��������
    iIncpid=(int16)(sptr->Kp*(iError-sptr->LastError)
            +sptr->Ki*iError
            +sptr->Kd*(iError-2*sptr->LastError+sptr->LLastError));
    //�����������´μ���

    sptr->LLastError=sptr->LastError;

    sptr->LastError=iError;

    return(iIncpid);
}

/************************************************
��������Dynamic_pid(PID *sptr, int16 Setpoint,int16 Turepiont)
��  �ܣ�PD���� (һ������ת�����)
************************************************/
int16 Dynamic_pid(PID *sptr, int16 Set_value,int16 real_value)
{
    int16 iError,dError,Actual;

    iError = Set_value - real_value;
		if(iError>200)
		{
			iError=200;
		}
		else if(iError<-200)
		{
			iError=-200;
		}
	
    dError=(iError-(sptr->LastError));
    Actual = (int16)(sptr->Kp * iError + sptr->Kd* dError);
    sptr->LastError = iError;
    return Actual;
}


void Set_PWM(int pwma,int pwmb)
{
	//��ʹ����˾��D153C����ģ���ʱ��PA12��AIN2��PA13��AIN1,PB16��BIN2��PB0����BIN1
	if(pwma>0) 
	{
		DL_GPIO_setPins(AIN1_PORT,AIN1_PIN_5_PIN);
		DL_GPIO_clearPins(AIN2_PORT,AIN2_PIN_6_PIN);
		DL_Timer_setCaptureCompareValue(PWM_INST,ABS(pwma),GPIO_PWM_C0_IDX);
	}
	else
	{
		DL_GPIO_setPins(AIN2_PORT,AIN2_PIN_6_PIN);
		DL_GPIO_clearPins(AIN1_PORT,AIN1_PIN_5_PIN);
		DL_Timer_setCaptureCompareValue(PWM_INST,ABS(pwma),GPIO_PWM_C0_IDX);
	}
	if(pwmb>0)
	{
		DL_GPIO_setPins(BIN1_PORT,BIN1_PIN_3_PIN);
		DL_GPIO_clearPins(BIN2_PORT,BIN2_PIN_4_PIN);
		DL_Timer_setCaptureCompareValue(PWM_INST,ABS(pwmb),GPIO_PWM_C1_IDX);
	}
    else
	{
		DL_GPIO_setPins(BIN2_PORT,BIN2_PIN_4_PIN);
		DL_GPIO_clearPins(BIN1_PORT,BIN1_PIN_3_PIN);
		DL_Timer_setCaptureCompareValue(PWM_INST,ABS(pwmb),GPIO_PWM_C1_IDX);
	}		

}