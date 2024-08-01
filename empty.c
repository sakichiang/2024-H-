/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "board.h"

float yaw=0;   //ŷ����


extern int16 count;
extern int16 count_3s;
extern int16 angle_zero;
extern int16 angle_err;
extern int16 Steer_pwm;  
extern int16 ADC_PWM;
extern int16 aim_angle;
extern int err_angle;
extern unsigned int ad[4];

extern int16 All_PWM_left;      //��������PWM���
extern int16 All_PWM_right;     //��������PWM���
extern uint16_t ad_value[6];

extern volatile bool swith_key1;
extern volatile bool swith_key2;

extern int16 Speed_pwm_all;     //����ƽ���ٶȻ�PWM��D���ã�
extern uint8_t mode_count;

int main(void)
{
		float pitch=0,roll=0;
	//�������ʼ��
		board_init();
	
    OLED_Init();     //��ʼ��OLED
    OLED_Clear();
		MPU6050_Init();
		PID_int();
    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
	  NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
		NVIC_EnableIRQ(KEY_INT_IRQN);//�����������ŵ�GPIOA�˿��ж�
		NVIC_EnableIRQ(ADC_VOLTAGE_INST_INT_IRQN);
    //DMP��ʼ��
    while( mpu_dmp_init() )
    {
        printf("dmp error\r\n");
        delay_ms(200);
    }
    aim_angle = 0;
		Speed_pwm_all = 150;

    while(1) 
    {		
			adc_getValue(ad);

		
        if( mpu_dmp_get_data(&pitch,&roll,&yaw) == 0 )
        { 
					OLED_ShowSignedNum(0,0,yaw-angle_zero,5,12,1);
					OLED_ShowSignedNum(0,12,(int)aim_angle,5,12,1);
					OLED_ShowSignedNum(0,24,(int)mode_count,5,12,1);
					OLED_ShowSignedNum(0,36,(int)yaw,5,12,1);
					OLED_ShowSignedNum(0,48,swith_key1,5,12,1);
					
					OLED_ShowSignedNum(16*5,0,ad[0],5,12,1);
					OLED_ShowSignedNum(16*5,12,ad[1],5,12,1);
					//OLED_ShowSignedNum(16*5,24,ad[2],5,12,1);
					OLED_ShowSignedNum(16*5,36,ad[3],5,12,1);
//					OLED_ShowSignedNum(16*5,0,ad[0],5,12,1);
//					OLED_ShowSignedNum(16*5,12,ad[1],5,12,1);
//					OLED_ShowSignedNum(16*5,24,ad[2],5,12,1);
//					OLED_ShowSignedNum(16*5,36,ad[3],5,12,1);
					
					
//					OLED_ShowSignedNum(16*5,0,err_angle,5,12,1);
//					OLED_ShowSignedNum(16*5,12,angle_zero,5,12,1);
					OLED_ShowSignedNum(16*5,24,mode_count,5,12,1);
//					OLED_ShowSignedNum(16*5,36,ad[3],5,12,1);
//					OLED_ShowSignedNum(16*5,48,swith_key2,5,12,1);
					//OLED_DisplayTurn(1);
					OLED_Refresh();
        }			
				
    }
}

