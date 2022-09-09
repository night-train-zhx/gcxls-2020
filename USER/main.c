#include "sys.h"
#include "main.h"
/**

OLED  PE2 ~ PE6
PWM   PA6  PA7  PB0  PB1
舵机  PA8.9.10.11   PD14.15
UART1 PB6  PB7 
UART3 PD8  PD9
UART4 PC10 PC11

按键  PA0
LED   PA1 //可以不用 就一个黄灯

**/
/**
 2020 - 12  -24
 搭配 _XYfine
 修复了 传输负数 失败的 问题
*/

void start_up(void)
{
	systick_Init();
//	led_Init(); //LED 里还开起了一个定时器 以完成 各种 闪烁
	key_Init(); //只有一个按键  选择功能 开始跑或者停止跑， 现在我设置的是开始跑
	oled_Init(); //调试完毕后，OLED为了把字放大。只保留 任务 ，
	
	motor_Init(MOTOR_ARR,MOTOR_PRE); /* 电机 */
	dj_Init(); /* 舵机 */
	
	usart1_Init(115200); /* 与_XY交互 */
	uart4_Init(9600);	  /* 等待 扫码器代码更换  */
	usart2_Init(9600); /* 串口屏 */
	
	
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
////	YPID.OUT_LIMIT =XPID.OUT_LIMIT *y_goal/ x_goal;//走同等距离，Y的输出一定比X大
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


