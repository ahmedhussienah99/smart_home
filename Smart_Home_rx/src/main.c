

#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SPI_INTERFACE.h"
//#include "LCD_INTERFACE.h"
//#include "KEYPAD_INTERFACE.h"

int main ( void ){
	u8 LOC_u8NewData  ;
	char x=0xff;
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOB_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , SPI1_RCC  );
	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC                  ) ;



	/*MGPIO_VidSetPinDirection( GPIOB , PIN5 , INPUT_FLOATING );//MOSI
	MGPIO_VidSetPinDirection( GPIOB , PIN4 , OUTPUT_SPEED_2MHZ_AFPP );//MISO

	MGPIO_VidSetPinDirection( GPIOB , PIN3 , INPUT_FLOATING );//CLOCK
	MGPIO_VidSetPinDirection( GPIOA , PIN15 , INPUT_FLOATING );
*/
	MGPIO_VidSetPinDirection( GPIOA , PIN10 , INPUT_FLOATING );
	MGPIO_VidSetPinDirection      ( GPIOA , PIN0 ,  OUTPUT_SPEED_2MHZ_PP         ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN1 ,  OUTPUT_SPEED_2MHZ_PP         ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN2 ,  OUTPUT_SPEED_2MHZ_PP         ) ;

	//MSPI_VidInit();
	MUSART_VidInit();


	while(1){


		LOC_u8NewData = MUSART1_u8RecCharSynch ();
		//MGPIO_VidSetPinValue( GPIOA , PIN0 , HIGH );
				if( LOC_u8NewData == '1'){MGPIO_VidSetPinValue( GPIOA , PIN0 , HIGH );}
				if( LOC_u8NewData =='0' ){MGPIO_VidSetPinValue( GPIOA , PIN0 , LOW ); }
				if( LOC_u8NewData =='3' ){MGPIO_VidSetPinValue( GPIOA , PIN1 , HIGH );}
				if( LOC_u8NewData =='4' ){MGPIO_VidSetPinValue( GPIOA , PIN1 , LOW ); }
				if( LOC_u8NewData =='5' ){MGPIO_VidSetPinValue( GPIOA , PIN2 , HIGH );}
				if( LOC_u8NewData =='6' ){MGPIO_VidSetPinValue( GPIOA , PIN2 , LOW ); }






	}





	return 0 ;
}
