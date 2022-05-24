#ifndef LCD_INTERFACE_H_INCLUDED
#define LCD_INTERFACE_H_INCLUDED




#define Data_Port  GPIOA
#define Control_Port GPIOB
#define PIN_RW 0
#define PIN_RS 1
#define PIN_EN 2

void HLCD_VoidDelay (void);
void HLCD_VoidSetFallingEdge(void);
void HLCD_VoidInit(void);
void HLCD_VoidWriteCommond(u8 Copy_u8Commond);
void HLCD_VoidWriteChar(u8 Copy_u8Char);
void HLCD_VoidWriteString(u8 *Copy_u8String);
void HLCD_VoidClearScreen();
void HLCD_VoidShift (u8 X,u8 Y);

#endif // LCD_INTERFACE_H_INCLUDED
