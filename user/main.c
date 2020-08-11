//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ��������ԭ��ս�� STM32������/mini������
//1.8��SPI����TFTҺ������
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtech.net
//�Ա���վ��http://qdtech.taobao.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:QDtech2008@gmail.com 
//Skype:QDtech2008
//��������:2013/5/13
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////	

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "delay.h"
#include "QDTFT_demo.h"
#include "Lcd_Driver.h"
#include "GUI.h"
#include "DTH11.h"
#include "usart.h"

DHT11_Data_TypeDef DHT11_Data;

void LED_GPIO_Config(void)	
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); // ʹ��PC�˿�ʱ��  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
  GPIO_SetBits(GPIOC, GPIO_Pin_13 );	 // �ر�����LED
}


int main(void)
{
char buf[100] ;
	int i = 0;
	SystemInit();	//System init.
	delay_init(72);//Delay init.
	LED_GPIO_Config();
	Lcd_Init();
	DHT11_GPIO_Config();

	Lcd_Clear(BLACK); //����

	USART1_Init(9600);
	while(1)  
{  
	if( Read_DHT11(&DHT11_Data)==SUCCESS)
		{
			printf("{\"h\":\"%d\",\"t\":\"%d\"} ",DHT11_Data.humi_int,DHT11_Data.temp_int);
			delay_ms(1500);		/* 1s ��ȡһ���¶�ֵ */
		}
		else
		{
		//printf("Read DHT11 ERROR!\r\n");//��ȡ����ʧ�ܣ����ڴ�ӡ��Read DHT11 ERROR.
			
		}	
	//	Gui_DrawFont_GBK16(16,0,BLUE,YELLOW,"bu");
		//Gui_DrawFont_GBK24( 0, 34,  BLUE, YELLOW , "��");
	
		//	QDTFT_Test_Demo();	//See the test details in QDTFT_Demo.c		
	//  GPIO_SetBits(GPIOC,GPIO_Pin_13);
		delay_ms(1000); 

		delay_ms(2000); 
		delay_ms(2000); 

	//  GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	//	printf("���\n");
}

}





/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
