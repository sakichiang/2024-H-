#include "fuse.h"
#include "PID.h"

PID SpeedPID = {0};
PID TurnPID ={0};
PID Turn_NeiPID ={0};

int16 aim_speed=0;
int16 real_speed=0;


int16 All_PWM_left = 0;      //��������PWM���
int16 All_PWM_right = 0;     //��������PWM���
int16 Speed_pwm_all = 0;     //����ƽ���ٶȻ�PWM��D���ã�
int16 Steer_pwm = 0;         //ת���ڻ�PWM
int16 ADC_PWM=0;
int16 angle_err=0;
int16 angle_zero=0;
int16 aim_angle=0;
uint8_t white_black=0;  //

int16 Current_Dir=0;
uint8_t mode_count = 0;

int16 count=0;
int16 count_3ms=0;
volatile bool swith_key1=0;
volatile bool swith_key2=0;
//bool swith_key1_pre=0;
//bool swith_key2_pre=0;
uint8_t count_3ms_flag=0;
extern uint16_t ad_value[6];
uint8_t GCdddddddddddount=0;
volatile bool turnEnable = false;



extern int16 count;
extern int16 count_3s;
extern int16 angle_err;
extern int16 Steer_pwm;  
extern int16 ADC_PWM;
extern int16 aim_angle;
extern int err_angle;
extern unsigned int ad[4];
extern int16 All_PWM_left;      //��������PWM���
extern int16 All_PWM_right;     //��������PWM���
extern float yaw; 



void swith_key(void)
{

	if(DL_GPIO_readPins(MODE1_PORT,MODE1_PIN_13_PIN) > 0)
	{
			swith_key1 = 1;
	}
	else
	{
			swith_key1 = 0;
	}
	
	if(DL_GPIO_readPins(MODE2_PORT,MODE2_PIN_16_PIN) > 0)
	{
			swith_key2 = 1;
	}
	else
	{
			swith_key2 = 0;
	}


}
/***************************************************************************************
��������int16 range_protect(int16 duty, int16 min, int16 max)
��  �ܣ��޷����� 
��  ����
����ֵ��duty
**************************************************************************************/
int16 range_protect(int16 duty, int16 min, int16 max)//�޷�����
{
  if (duty > max)   return max;
  
  if (duty < min)   return min;
  
  return duty;
}

/****************************PID������ʼ��**************************************
������  void PID_int(void)
������  void
˵����  PIDÿ����������ʼ��
����ֵ��void
********************************************************************************/
void PID_int(void)
{
	SpeedPID.Kp=1;
	SpeedPID.Ki=1;    
	SpeedPID.Kd=0;
	
	TurnPID.Kp=1.9;     
	TurnPID.Ki=0;
	TurnPID.Kd=0.6;         
	
	Turn_NeiPID.Kp=3;  //3
	Turn_NeiPID.Ki=0.001;//0.001
	Turn_NeiPID.Kd=2;//2
}

/**********************************************
��  �ܣ��ٶȻ��������   2ms
**********************************************/
void speed_pwm(void)
{
	       //����������
	
	Speed_pwm_all += IncPIDCalc(&SpeedPID,aim_speed,real_speed); //D���ٶȻ�
	Speed_pwm_all=range_protect(Speed_pwm_all,-8000,8000); 
}

/****************************ת�򻷣�D��ת���⻷��**************************************
������  void turn_pid()
������  void
˵����  ת�򻷣�D��ת���⻷��//6ms
����ֵ��void
***************************************************************************************/
void turn_pid()
{
		Data_current_analyze();
        if(ad_value[4]==0&&ad_value[5]==0)
        {
            Current_Dir = (int16) Cha_bi_he((ad_value[0]+ad_value[1]),(ad_value[2]+ad_value[3]),100);
        }
#if 1
         else
        {
            Current_Dir = (int16) Cha_bi_he((ad_value[0]+ad_value[1]),(ad_value[2]+ad_value[3]),100);
        }
#endif
        
        //key1=0,key2=1
        if(swith_key1==0&&swith_key2==1)
        {

            if(mode_count==1)
            {
                if(ad_value[4]==100)
                {
                    Current_Dir = 80;
                }
                else if(ad_value[5]==100)
                {
                    Current_Dir = -80;
                }
            }
           
            if(mode_count==3){
              if(ad_value[5]==100)
            {

                Current_Dir = -80;
                }
                else if(ad_value[4]==100)
             {

                Current_Dir = 80;
                }
            }
        }
        else if(swith_key1==1&&swith_key2==1)
        {

            if(mode_count==1)
            {
                if(ad_value[4]==100)
                {
                    Current_Dir = 80;
                }
                else if(ad_value[5]==100)
                {
                    Current_Dir = -80;
                }
            }
           
            else if(mode_count==3){
              if(ad_value[5]==100)
            {

                Current_Dir = -80;
                }
                else if(ad_value[4]==100)
             {

                Current_Dir = 80;
                }
            }

            else if(mode_count==5)
            {
                if(ad_value[4]==100)
                {
                    Current_Dir = 80;
                }
                else if(ad_value[5]==100)
                {
                    Current_Dir = -80;
                }
            }
           
            else if(mode_count==7){
              if(ad_value[5]==100)
            {

                Current_Dir = -80;
                }
                else if(ad_value[4]==100)
             {

                Current_Dir = 80;
                }
            }

            else if(mode_count==9)
            {
                if(ad_value[4]==100)
                {
                    Current_Dir = 80;
                }
                else if(ad_value[5]==100)
                {
                    Current_Dir = -80;
                }
            }
           
            else if(mode_count==11){
              if(ad_value[5]==100)
            {

                Current_Dir = -80;
                }
                else if(ad_value[4]==100)
             {

                Current_Dir = 80;
                }
            }

            else if(mode_count==13)
            {
                if(ad_value[4]==100)
                {
                    Current_Dir = 80;
                }
                else if(ad_value[5]==100)
                {
                    Current_Dir = -80;
                }
            }
           
            else if(mode_count==15){
              if(ad_value[5]==100)
            {

                Current_Dir = -80;
                }
                else if(ad_value[4]==100)
             {

                Current_Dir = 80;
                }
            }

            
        }

        else {
             if(ad_value[4]==100)
                {
                    Current_Dir = 80;
                }
                else if(ad_value[5]==100)
                {
                    Current_Dir = -80;
                }
        }
       
       
		
	  ADC_PWM = Dynamic_pid(&TurnPID,Current_Dir,0);//λ��ʽPD����ת��
	  ADC_PWM=range_protect(ADC_PWM,-9000,9000);
}

/**********************************************
��  �ܣ�����ת���ڻ� 2ms
**********************************************/
void angle_pid()
{
		angle_err = yaw - angle_zero;
			if(angle_err<(-180))
	{
		angle_err+=360;
	}
	else	if(angle_err>(180))
	{
		angle_err-=360;
	}
	else
	{
		angle_err=angle_err;
	}
		Steer_pwm=position_pid(&Turn_NeiPID,aim_angle,angle_err);   //ת���ڻ�PWM	
    Steer_pwm=range_protect(Steer_pwm,-9000,9000);                //ת���ڻ�PWM�޷�
}


/**********************************************
��  �ܣ��ٶȻ���ת���ں�
**********************************************/
void speed_turn_out()
{
	if(white_black == 0)  //��
	{
			All_PWM_left =Speed_pwm_all - Steer_pwm;                         //��������PWM��� 
			All_PWM_right=Speed_pwm_all + Steer_pwm;                        //�ҵ������PWM���
	}
	else  //��
	{
		All_PWM_left =Speed_pwm_all - ADC_PWM;                         //��������PWM��� 
		All_PWM_right=Speed_pwm_all + ADC_PWM;                        //�ҵ������PWM���
	}

	All_PWM_left =range_protect(All_PWM_left,-1000,1000);                        
	All_PWM_right=range_protect(All_PWM_right,-1000,1000);                        
	
  Set_PWM(All_PWM_left,All_PWM_right);                         //�������
}



void ledandbeep(void)
{
	if(count_3ms_flag)
	DL_GPIO_setPins(LED_PORT,LED_PIN_17_PIN);
	
	if(count_3ms>=250)
	{
		count_3ms_flag= 0;
		DL_GPIO_clearPins(LED_PORT,LED_PIN_17_PIN);
		count_3ms = 0;
	}
}

//void check_balck(void)
//{
//	static uint8_t white_last=0;
//	
//		if(ad_value[0]<=25 || ad_value[1]<=25 || ad_value[2]<=25 || ad_value[3]<=25 )
//		{
//			white_black = 1;
//		}
//		else
//		{
//			white_black = 0;
//		}
//		if(white_last != white_black)
//		{
//			count_3ms_flag=1;
//			mode_count++;
//		}
//		white_last = white_black;	
//}

void check_balck(void)
{
    static uint8_t white_last = 0;
    static uint8_t stable_count = 0;
    bool way1;
    bool way2;
    bool way3;
    bool way4;
    const uint8_t stable_threshold = 10; // 稳定阈值
    if (DL_GPIO_readPins(WAY_PORT, WAY_PIN_12_PIN) > 0) 
        way1 = 1;
    else 
        way1 = 0;

    if(DL_GPIO_readPins(WAY_PORT, WAY_PIN_9_PIN) > 0) 
        way2 = 1;
    else 
        way2 = 0;
    if(DL_GPIO_readPins(WAY_PORT, WAY_PIN_10_PIN) > 0) 
        way3 = 1;
    else 
        way3 = 0;

    uint8_t current_white_black;
    if (ad_value[0] <= 25 || ad_value[1] <= 25 || ad_value[2] <= 25 || ad_value[3] <= 25 || way1 == 1 || way2 == 1 || way3 == 1) 
        current_white_black = 1;
    else 
        current_white_black = 0;

    if (current_white_black != white_last)
    {
        stable_count++;
        if (stable_count >= stable_threshold)
        {
            if (swith_key1 == 0 && swith_key2 == 0)
            {
                white_black = current_white_black;
                white_last = white_black;
                stable_count = 0;
                mode_count++;
                count_3ms_flag = 1;
            }
            else if (swith_key1 == 1 && swith_key2 == 0)
            {
                if (mode_count == 0) 
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
                else if (mode_count == 1) 
                {
                    if (ABS(angle_err) >= 150) 
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        mode_count++;
                    }
                }
                else if (mode_count == 2) 
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
                else if (mode_count == 3) 
                {
                    if (ABS(angle_err) <= 30) 
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        mode_count++;
                    }
                }
            }
            else if (swith_key1 == 0 && swith_key2 == 1)
            {
                if (mode_count == 0)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
                else if (mode_count == 1)
                {
                    if (yaw >= 150)
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        mode_count++;
                        angle_zero = yaw;
                    }
                }
                else if (mode_count == 2)
                {
                    if (ABS(yaw) >= 120)
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        angle_zero = yaw;
                        mode_count++;
                    }
                }
                else if (mode_count == 3)
                {
                    if (ABS(yaw) <= 30)
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        mode_count++;
                    }
                }
            }
            else if (swith_key1 == 1 && swith_key2 == 1)
            {
                if (mode_count == 0)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
                else if (mode_count == 1)
                {
                    if (yaw >= 150)
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        mode_count++;
                        angle_zero = yaw;
                    }
                }
                else if (mode_count == 2)
                {
                    if (ABS(yaw) >= 120)
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        angle_zero = yaw;
                        mode_count++;
                    }
                }
                else if (mode_count == 3)
                {
                    if (ABS(yaw) <= 30)
                    {
                        white_black = current_white_black;
                        white_last = white_black;
                        stable_count = 0;
                        count_3ms_flag = 1;
                        mode_count++;
                    }
                }

                 else if (mode_count == 4)
            {
                if (ABS(yaw) <= 30)
                {
                    angle_zero = yaw;
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
            }
            else if (mode_count == 5)
            {
                if (yaw >= 150)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                    angle_zero = yaw;
                }
            }
            else if (mode_count == 6)
            {
                if (ABS(yaw) >= 120)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    angle_zero = yaw;
                    mode_count++;
                }
            }
            else if (mode_count == 7)
            {
                if (ABS(yaw) <= 30)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
            }
            else if (mode_count == 8)
            {
                if (ABS(yaw) <= 30)
                {
                    angle_zero = yaw;
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
            }
            else if (mode_count == 9)
            {
                if (yaw >= 150)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                    angle_zero = yaw;
                }
            }
            else if (mode_count == 10)
            {
                if (ABS(yaw) >= 120)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    angle_zero = yaw;
                    mode_count++;
                }
            }
            else if (mode_count == 11)
            {
                if (ABS(yaw) <= 30)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
            }
            else if (mode_count == 12)
            {
                if (ABS(yaw) <= 30)
                {
                    angle_zero = yaw;
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
            }
            else if (mode_count == 13)
            {
                if (yaw >= 150)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                    angle_zero = yaw;
                }
            }
            else if (mode_count == 14)
            {
                if (ABS(yaw) >= 120)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    angle_zero = yaw;
                    mode_count++;
                }
            }
            else if (mode_count == 15)
            {
                if (ABS(yaw) <= 30)
                {
                    white_black = current_white_black;
                    white_last = white_black;
                    stable_count = 0;
                    count_3ms_flag = 1;
                    mode_count++;
                }
            }
            }
           
        }
    }
    else
    {
        stable_count = 0;
    }
}

bool stayTurn(int16 angle,uint16_t *turnCount)
{
	if(++(*turnCount) <=700){
		Speed_pwm_all =0;
		aim_angle = angle;	
		turnEnable = true;
		return false;
	}
	else 
	{
		turnEnable = false;
		//*turnCount = 0;
		return true;
	}

	
	
}

void main_control(void)
{
    static uint16_t turnCount = 0;
    static bool turnCountSet = 0,zeroSet=0;
    swith_key();
    //swith_key1_pre=swith_key1;
    //swith_key2_pre=swith_key2;

    if (mode_count != 0 && swith_key1 == 0 && swith_key2 == 0)
    {
        Set_PWM(0, 0);
        DL_GPIO_clearPins(start_PORT, start_PIN_15_PIN);
    }
    if (swith_key1 == 1 && swith_key2 == 0)
    {
        if (mode_count >= 4)
        {
            Set_PWM(0, 0);
            DL_GPIO_clearPins(start_PORT, start_PIN_15_PIN);
        }
        if (mode_count == 2)
        {
            //angle_zero=yaw;
            aim_angle = 360-172;
        }
    }

    if (swith_key1 == 0 && swith_key2 == 1)
    {
        if (mode_count == 0)
        {
            if (!turnCountSet)
            {
                turnCount = 0;
                turnCountSet = true;
            }

            if (stayTurn(-38, &turnCount))
                {
					if(!zeroSet)
					{
						angle_zero = yaw;
						aim_angle=0;
						zeroSet = true;
					}
				
				
				
				}
        }
        else if (mode_count == 1)
        {
            turnCountSet = false;
			zeroSet = false;
        }
        else if (mode_count == 2)
        {
            if (!turnCountSet)
            {
                turnCount = 0;
                turnCountSet = true;
            }
            if (stayTurn(45, &turnCount)){
				if(!zeroSet)
				{
					angle_zero = yaw;
					aim_angle=0;
					zeroSet = true;
				}

			}

        }
        else if (mode_count == 3)
        {
			zeroSet = false;
            turnCountSet = false;
        }
        else if (mode_count >= 4)
        {
            Set_PWM(0, 0);
            DL_GPIO_clearPins(start_PORT, start_PIN_15_PIN);
        }
    }

      if (swith_key1 == 1 && swith_key2 == 1)
    {
        if (mode_count == 0)
        {
            if (!turnCountSet)
            {
                turnCount = 0;
                turnCountSet = true;
            }

            if (stayTurn(-38, &turnCount))
                {
					if(!zeroSet)
					{
						angle_zero = yaw;
						aim_angle=0;
						zeroSet = true;
					}
				
				
				
				}
        }
        else if (mode_count == 1)
        {
            turnCountSet = false;
			zeroSet = false;
        }
        else if (mode_count == 2)
        {
            if (!turnCountSet)
            {
                angle_zero = yaw;
                turnCount = 0;
                turnCountSet = true;
            }
            if (stayTurn(45, &turnCount)){
				if(!zeroSet)
				{
					angle_zero = yaw;
					aim_angle=0;
					zeroSet = true;
				}

			}

        }
        else if (mode_count == 3)
        {
			zeroSet = false;
            turnCountSet = false;
        }
        else if (mode_count == 4)
        {
            if (!turnCountSet)
            {
                angle_zero = yaw;
                turnCount = 0;
                turnCountSet = true;
            }

            if (stayTurn(-44, &turnCount))
                {
					if(!zeroSet)
					{
						angle_zero = yaw;
						aim_angle=0;
						zeroSet = true;
					}
				
				
				
				}
        }
        else if (mode_count == 5)
        {
            turnCountSet = false;
			zeroSet = false;
        }
        else if (mode_count == 6)
        {
            if (!turnCountSet)
            {
                angle_zero = yaw;
                turnCount = 0;
                turnCountSet = true;
            }
            if (stayTurn(45, &turnCount)){
				if(!zeroSet)
				{
					angle_zero = yaw;
					aim_angle=0;
					zeroSet = true;
				}

			}

        }
        else if (mode_count == 7)
        {
			zeroSet = false;
            turnCountSet = false;
        }
        else if (mode_count == 8)
        {
            if (!turnCountSet)
            {
                angle_zero = yaw;
                turnCount = 0;
                turnCountSet = true;
            }

            if (stayTurn(-44, &turnCount))
                {
					if(!zeroSet)
					{
						angle_zero = yaw;
						aim_angle=0;
						zeroSet = true;
					}
				
				
				
				}
        }
        else if (mode_count == 9)
        {
            turnCountSet = false;
			zeroSet = false;
        }
        else if (mode_count == 10)
        {
            if (!turnCountSet)
            {
                angle_zero = yaw;
                turnCount = 0;
                turnCountSet = true;
            }
            if (stayTurn(45, &turnCount)){
				if(!zeroSet)
				{
					angle_zero = yaw;
					aim_angle=0;
					zeroSet = true;
				}

			}

        }
        else if (mode_count == 11)
        {
			zeroSet = false;
            turnCountSet = false;
        }
        else if (mode_count == 12)
        {
            if (!turnCountSet)
            {
                angle_zero = yaw;
                turnCount = 0;
                turnCountSet = true;
            }

            if (stayTurn(-44, &turnCount))
                {
					if(!zeroSet)
					{
						angle_zero = yaw;
						aim_angle=0;
						zeroSet = true;
					}
				
				
				
				}
        }
        else if (mode_count == 13)
        {
            turnCountSet = false;
			zeroSet = false;
        }
        else if (mode_count == 14)
        {
            if (!turnCountSet)
            {
                angle_zero = yaw;
                turnCount = 0;
                turnCountSet = true;
            }
            if (stayTurn(45, &turnCount)){
				if(!zeroSet)
				{
					angle_zero = yaw;
					aim_angle=0;
					zeroSet = true;
				}

			}

        }
        else if (mode_count == 15)
        {
			zeroSet = false;
            turnCountSet = false;
        }
        else if (mode_count >= 16)
        {
            Set_PWM(0, 0);
            DL_GPIO_clearPins(start_PORT, start_PIN_15_PIN);
        }
    }
}
void speed_change(void)
{	
	if(turnEnable==true)
	{
		Speed_pwm_all = 0;
	}
	else if(swith_key1==0&&swith_key2==0)
	{
		Speed_pwm_all = 250;
	}
	else if(swith_key1==1&&swith_key2==0)
	{
		Speed_pwm_all = 150;
	}
	else if(swith_key1==0&&swith_key2==1)
	{
		Speed_pwm_all = 150;
	}
    else if(swith_key1==1&&swith_key2==1)
	{
		Speed_pwm_all = 150;
	}
}



void ALL_control()
{
  if(count%2==0)  //2msִ��һ��ת���ڻ�
	{		
//		swith_key();
		turn_pid();
		check_balck();
    ledandbeep(); 
		main_control();		
//		 //speed_pwm(); //�ٶȻ�
		//angle_chenge();//
		angle_pid(); //ת���ڻ�
		speed_change();
		speed_turn_out(); //���յ�����
		count=0;
   }
}


//��ʱ�����жϷ����� ������Ϊ1�������
void TIMER_0_INST_IRQHandler(void)
{
    //��������˶�ʱ���ж�
    switch( DL_TimerG_getPendingInterrupt(TIMER_0_INST) )
    {
        case DL_TIMER_IIDX_ZERO://�����0����ж�
            //��LED�Ƶ�״̬��ת
            count++;
					if(count_3ms_flag)
					{
						count_3ms++;
					}
					
						ALL_control();
            break;
        
        default://�����Ķ�ʱ���ж�
            break;
    }
}

void GROUP1_IRQHandler(void)//Group1���жϷ�����
{
    //��ȡGroup1���жϼĴ���������жϱ�־λ
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
        //����Ƿ���KEY��GPIOA�˿��жϣ�ע����INT_IIDX������PIN_18_IIDX 
        case KEY_INT_IIDX:
            //����������±�Ϊ�ߵ�ƽ
            if( DL_GPIO_readPins(KEY_PORT, KEY_PIN_18_PIN) > 0 )
            {
                //����LED����״̬��ת
              angle_zero = yaw;
							DL_GPIO_setPins(start_PORT,start_PIN_15_PIN);
							NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);

							
            }
        break;
    }
}