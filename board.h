/*
 * ������������Ӳ�������������չ����Ӳ�����Ϲ���ȫ����Դ
 * �����������www.lckfb.com
 * ����֧�ֳ�פ��̳���κμ������⻶ӭ��ʱ����ѧϰ
 * ������̳��https://oshwhub.com/forum
 * ��עbilibili�˺ţ������������塿���������ǵ����¶�̬��
 * ��������׬Ǯ���������й�����ʦΪ����
 * Change Logs:
 * Date           Author       Notes
 * 2024-05-23     LCKFB     first version
 */
#ifndef	__BOARD_H__
#define __BOARD_H__

#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "bsp_mpu6050.h"
#include "oled.h"
#include "inv_mpu.h"
#include "PID.h"
#include "fuse.h"
#include "ADC.h"


#define ABS(a)      (a>0 ? a:(-a))

void board_init(void);

void delay_us(unsigned long __us);
void delay_ms(unsigned long ms);
void delay_1us(unsigned long __us);
void delay_1ms(unsigned long ms);

void uart0_send_char(char ch);
void uart0_send_string(char* str);
void Data_current_analyze(void);
float Cha_bi_he(int16 data1, int16 data2,int16 x);

extern		float pitch,roll,yaw;   //ŷ����

#endif
