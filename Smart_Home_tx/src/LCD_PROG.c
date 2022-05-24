



#include"TYPES.h"
#include"MACROS.h"
#include"ERROR_STATUS.h"
#include"GPIO_INTERFACE.h"
#include"LCD_INTERFACE.h"
#include"LCD_CONFIG.h"

void HLCD_VidDelay (void)
{
	for(u8 i = 0 ; i < 100 ; i++ )
	{
		for(u8 j = 0 ; j < 100 ; j++ )
		{
			asm("NOP");
		}
	}
}
void main_VidDelay (void)
{
	for(u8 i = 0 ; i < 250 ; i++ )
	{
		for(u8 j = 0 ; j < 250 ; j++ )
		{
			asm("NOP");
		}
	}
}

/*Vid HLCD_VidSetFallingEdge(Vid){
//MGPIO_VidSetPinDirection(Control_Port,2,OUTPUT_SPEED_10MHZ_PP);//EN
MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,0);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN

}*/
//###############################

void HLCD_VidWriteCommond(u8 Copy_u8Commond){

MGPIO_VidSetPinValue(Control_Port,PIN_RS,0); //RS 0 TO COMMOND
/*MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,0);//2--PIN EN
HLCD_VidDelay();*/
MGPIO_VidSetPortValue(Data_Port,LOW,Copy_u8Commond);
MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,0);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN

//Vid HLCD_VidSetFallingEdge();

}

void HLCD_VidInit(void){

// 8BITS OF DATA
MGPIO_VidSetPinDirection(Data_Port,0,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(Data_Port,1,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(Data_Port,2,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(Data_Port,3,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(Data_Port,4,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(Data_Port,5,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(Data_Port,6,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(Data_Port,7,OUTPUT_SPEED_2MHZ_PP);

MGPIO_VidSetPinDirection(Control_Port,PIN_RW,OUTPUT_SPEED_2MHZ_PP);//RW
MGPIO_VidSetPinDirection(Control_Port,PIN_RS,OUTPUT_SPEED_2MHZ_PP);//RS
MGPIO_VidSetPinDirection(Control_Port,PIN_EN,OUTPUT_SPEED_2MHZ_PP);//EN

MGPIO_VidSetPinValue(Control_Port,PIN_RW,0);
HLCD_VidDelay();
HLCD_VidWriteCommond(0b00111000); //FUNCTION SET 0X38
HLCD_VidDelay();

HLCD_VidWriteCommond(0b00001111);//DISPLAY ON/OFF
HLCD_VidDelay();

HLCD_VidWriteCommond(0b00000001);//DISPLAY CLEAR 0X01
HLCD_VidDelay();

HLCD_VidWriteCommond(0b00000110);//ENTRYMODE 0X06
HLCD_VidDelay();

}


//########################################
void HLCD_VidWriteChar(u8 Copy_u8Char){

MGPIO_VidSetPinValue(Control_Port,PIN_RS,1); //RS 1 to data
/*MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,0);//2--PIN EN
HLCD_VidDelay();*/
MGPIO_VidSetPortValue(Data_Port,LOW,Copy_u8Char);
MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,0);//2--PIN EN
HLCD_VidDelay();
MGPIO_VidSetPinValue(Control_Port,PIN_EN,1);//2--PIN EN
/*Vid HLCD_VidSetFallingEdge();
HLCD_VidDelay();*/

}


void HLCD_VidWriteString(u8 *Copy_u8String){

    while(((*Copy_u8String)!=0)){
        HLCD_VidWriteChar(*Copy_u8String);
        Copy_u8String++;
    }
}

void HLCD_VidClearScreen(){
    HLCD_VidWriteCommond (0x01);		/* clear display */
	HLCD_VidWriteCommond (0x02);		/* cursor at home position */
}

void HLCD_VidShift (u8 X,u8 Y)
{
	/*
	  2*16 LCD
			    {80 81 ... 8F}   0X80 = 128  :Force cursor to beginning of the first line
			    {C0 C1 ... CF}   0XC0 = 192  :Force cursor to beginning of the SECOND line

	*/
	if (((X>0) && (X<=16)))           // x from 1 to 16 , y : 1 or 2

			switch(Y)
			{
				case 1:
					HLCD_VidWriteCommond(X+127);
				break;
				case 2:
					HLCD_VidWriteCommond(X+191);
				break;
				default:    break;
			}

}
