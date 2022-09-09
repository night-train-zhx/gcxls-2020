#include "sys.h"
#include "main.h"
/**

OLED  PE2 ~ PE6
PWM   PA6  PA7  PB0  PB1
���  PA8.9.10.11   PD14.15
UART1 PB6  PB7 
UART3 PD8  PD9
UART4 PC10 PC11

����  PA0
LED   PA1 //���Բ��� ��һ���Ƶ�

**/
/**
 2020 - 12  -24
 ���� _XYfine
 �޸��� ���为�� ʧ�ܵ� ����
*/

void start_up(void)
{
	systick_Init();
//	led_Init(); //LED �ﻹ������һ����ʱ�� ����� ���� ��˸
	key_Init(); //ֻ��һ������  ѡ���� ��ʼ�ܻ���ֹͣ�ܣ� ���������õ��ǿ�ʼ��
	oled_Init(); //������Ϻ�OLEDΪ�˰��ַŴ�ֻ���� ���� ��
	
	motor_Init(MOTOR_ARR,MOTOR_PRE); /* ��� */
	dj_Init(); /* ��� */
	
	usart1_Init(115200); /* ��_XY���� */
	uart4_Init(9600);	  /* �ȴ� ɨ�����������  */
	usart2_Init(9600); /* ������ */
	
	
	PID_Init(); /* PID */	
	Scheduler_Setup();	
	delay_ms(1000);	
	FLAG.Init_finish = 1;
}




int main(void)
{	
 	start_up();
	
	Code.first_num = 3;
	Code.second_num =1;
	Code.third_num = 2;
	
	
	
//	_XY[x] = 0;
//	_XY[y] = 0;

//	
//	x_goal = 1650.0f;
//	y_goal = 430.0f;
//	
	XPID.OUT_LIMIT = 1100.0f;
	YPID.OUT_LIMIT = 800.0f;
//	
////	YPID.OUT_LIMIT =XPID.OUT_LIMIT *y_goal/ x_goal;//��ͬ�Ⱦ��룬Y�����һ����X��
////	if(YPID.OUT_LIMIT<=700)
////		YPID.OUT_LIMIT = 700;
//	
//	APID.OUT_LIMIT = 1500.0f;
	
//	MOTOR4_SPEED = 1000;
//		MOTOR4_R;
//	MOTOR4_R;
//		MOTOR3_SPEED = 1000;
//	MOTOR3_R;
//		MOTOR2_SPEED = 1000;
//	MOTOR2_R;
//		MOTOR4_SPEED = 1000;
//	MOTOR1_R;
//		MOTOR1_SPEED = 1000;

	while(1)
	{
		
				Scheduler_Run();
	}
}



#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
	while(1)
	{
		/* printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	}
}
#endif



/* end of main.c */


