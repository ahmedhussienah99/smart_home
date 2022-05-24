

#include"TYPES.h"
#include"MACROS.h"
#include"ERROR_STATUS.h"
#include"GPIO_INTERFACE.h"
#include"KEYPAD_INTERFACE.h"
#include"KEYPAD_CONFIG.h"
#include"LCD_INTERFACE.h"

#define NOTPRESSED  0xff

void HKEYPAD_VidDelay (void)
{
	for(u8 i = 0 ; i < 100; i++ )
	{
		for(u8 j = 0 ; j < 100 ; j++ )
		{
			asm("NOP");
		}
	}
}

void HKEYPAD_VidInit(){

//pins of colums will output 1
MGPIO_VidSetPinDirection(HKEYPAD_PORT,C0,INPUT_PULLUP_PULLDOWN);
MGPIO_VidSetPinDirection(HKEYPAD_PORT,C1,INPUT_PULLUP_PULLDOWN);
MGPIO_VidSetPinDirection(HKEYPAD_PORT,C2,INPUT_PULLUP_PULLDOWN);
MGPIO_VidSetPinDirection(HKEYPAD_PORT,C3,INPUT_PULLUP_PULLDOWN);
MGPIO_VidSetPinValue(HKEYPAD_PORT,C0,1);// DO IT PULL UP TO SENSITIVE TO LOW
MGPIO_VidSetPinValue(HKEYPAD_PORT,C1,1);
MGPIO_VidSetPinValue(HKEYPAD_PORT,C2,1);
MGPIO_VidSetPinValue(HKEYPAD_PORT,C3,1);
MGPIO_VidSetPinDirection(HKEYPAD_PORT,R0,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(HKEYPAD_PORT,R1,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(HKEYPAD_PORT,R2,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinDirection(HKEYPAD_PORT,R3,OUTPUT_SPEED_2MHZ_PP);
MGPIO_VidSetPinValue(HKEYPAD_PORT,R0,1);
		 MGPIO_VidSetPinValue(HKEYPAD_PORT,R1,1);
		 MGPIO_VidSetPinValue(HKEYPAD_PORT,R2,1);
		 MGPIO_VidSetPinValue(HKEYPAD_PORT,R3,1);



	}
char HkEYPAD_u8GetPress(){
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 int row,coloumn,x;
	 char returnval=NOTPRESSED;
	 int i,j;
	 for(i=0;i<4;i++)
	 {
		 //HKEYPAD_VidDelay();
		MGPIO_VidSetPinValue(HKEYPAD_PORT,(i+8),0);
		//HKEYPAD_VidDelay();
		// HKEYPAD_VidDelay();

	for(j=0;j<4;j++)
	{
	 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,(j+12))==0){

		  returnval=arr[i][j];
			 while(MGPIO_u8GetPinValue(HKEYPAD_PORT,(j+12))==0);
			 HKEYPAD_VidDelay();

	 }
	// HKEYPAD_VidDelay();
	}
		MGPIO_VidSetPinValue(HKEYPAD_PORT,(i+8),1);

	 }



	  return returnval ;
	  }

/*
char HkEYPAD_u8GetPress(){
    // i will loop on pins row input
    MGPIO_VidSetPinValue(HKEYPAD_PORT,R0,0);
    MGPIO_VidSetPinValue(HKEYPAD_PORT,R1,1);
    MGPIO_VidSetPinValue(HKEYPAD_PORT,R2,1);
    MGPIO_VidSetPinValue(HKEYPAD_PORT,R3,1);

                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){

               while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
              // HKEYPAD_VidDelay();
           	return'7';

                	}
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){
                while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                //HKEYPAD_VidDelay();
           	 return'8';

                	}
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){

                while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                //HKEYPAD_VidDelay();
           	 return'/';

                	}
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){
               	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	//HKEYPAD_VidDelay();
               	 return'o';

                	}
                 HKEYPAD_VidDelay();

                    MGPIO_VidSetPinValue(HKEYPAD_PORT,R0,1);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R1,0);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R2,1);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R3,1);



                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
                	//HKEYPAD_VidDelay();
                	return'4';

                	}
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){
                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                	//HKEYPAD_VidDelay();
               	 return'5';

                	}
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                	//HKEYPAD_VidDelay();
               	 return'6';

                	}
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	//HKEYPAD_VidDelay();
               	 return'*';

                }
                 HKEYPAD_VidDelay();

                 	 MGPIO_VidSetPinValue(HKEYPAD_PORT,R0,1);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R1,1);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R2,0);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R3,1);


                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
                	//HKEYPAD_VidDelay();
                	return'1';

                }
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                	//HKEYPAD_VidDelay();
               	 return'2';

                }
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                	//HKEYPAD_VidDelay();
               	 return'3';

                }
                 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	//HKEYPAD_VidDelay();
               	 return'-';

                }

                 HKEYPAD_VidDelay();

                 	 MGPIO_VidSetPinValue(HKEYPAD_PORT,R0,1);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R1,1);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R2,1);
                     MGPIO_VidSetPinValue(HKEYPAD_PORT,R3,0);





                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
                	//HKEYPAD_VidDelay();
                	return'o';

                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                	//HKEYPAD_VidDelay();
                	return'0';

                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){
                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                	//HKEYPAD_VidDelay();
                	return'=';

                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	//HKEYPAD_VidDelay();
                	return'+';

                }


                HKEYPAD_VidDelay();
}
*/

/*
char HkEYPAD_u8GetPress(){
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 int row,coloumn,x;
	 char returnval=NOTPRESSED;
	 int i,j;
	 for(i=0;i<4;i++)
	 {
		 //row=i+R0;
		// MGPIO_VidSetPinValue(HKEYPAD_PORT,row,0);
		 HKEYPAD_VidDelay();
	for(j=0;j<4;j++)
	{
		coloumn=j+C0;
	 //x=MGPIO_u8GetPinValue(HKEYPAD_PORT,coloumn);
	 HKEYPAD_VidDelay();

	 while(MGPIO_u8GetPinValue(HKEYPAD_PORT,coloumn)==0)
	  {
		 x=0;
	  returnval=arr[i][j];
	  break;
	  }
	 }
	  if(x==0)
	 {
	  break;
	 }
	  }
	  return returnval ;
	  }

*/


/*
char HkEYPAD_u8GetPress(){

	 //char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 int row,coloumn;
	 char returnval=NOTPRESSED;
	 int i,j;

	 for(i=0;i<4;i++)
	 {
		 	 	 	 MGPIO_VidSetPinValue(HKEYPAD_PORT,C0,1);
		 			 MGPIO_VidSetPinValue(HKEYPAD_PORT,C1,1);
		 			 MGPIO_VidSetPinValue(HKEYPAD_PORT,C2,1);
		 			 MGPIO_VidSetPinValue(HKEYPAD_PORT,C3,1);
		 			coloumn=i+12;

		 			 MGPIO_VidSetPinValue(HKEYPAD_PORT,coloumn,0);

		 for(j=0;j<4;j++)
		 {
			 row=j+8;
			 HKEYPAD_VidDelay();

			 if(MGPIO_u8GetPinValue(HKEYPAD_PORT,row)==0)
			 {
			// while( MGPIO_u8GetPinValue(HKEYPAD_PORT,row)==0);

				 switch(coloumn){

				       case C0:{
				                if (row==R0){return'7';}
				                else if (row==R1){return'4';}
				                else if (row==R2){return'1';}
				                else if (row==R3){return'p';}
				                break;
				       }

				       case C1:{
				    	    if (row==R0){return'8';}
				    	   else if (row==R1){return'5';}
				           else if (row==R2){return'2';}
				    	   else if (row==R3){return'0';}
				    	   break;
				       }
				       case C2:
				       {
				    	   if (row==R0){return'9';}
				    	   else if (row==R1){return'6';}
				    	   else if (row==R2){return'3';}
				    	   else if (row==R3){return'=';}
				    	   break;
				       }
				    case C3:
				    {
				    	if (row==R0){return'/';}
				    	else if (row==R1){return'*';}
				    	else if (row==R2){return'-';}
				    	else if (row==R3){return'+';}
				    	break;
				    }

				       }
			 }
		 }
		 HKEYPAD_VidDelay();
			  }
	 return 'A'; // IF NOT PREESSED
			  }

*/
/*
char HkEYPAD_u8GetPress(){
    // i will loop on pins row input
    u8 result;
    for(int i=0;i<4;i++){

       switch(i){

       case 0:{
                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){
                	result='7';

               while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
               HKEYPAD_VidDelay();
                	}
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){
                	result='4';
                while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                HKEYPAD_VidDelay();
                	}
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){
                	result='1';

                while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                HKEYPAD_VidDelay();
                	}
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){
                	result='o';
                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	HKEYPAD_VidDelay();
                	}

                break;
       }
       case 1:
       {
    	   MGPIO_VidSetPinValue(HKEYPAD_PORT,C1,1);

                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){
                	result='8';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
                	HKEYPAD_VidDelay();
                	}
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){
                	result='5';
                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                	HKEYPAD_VidDelay();
                	}
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){
                	result='2';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                	HKEYPAD_VidDelay();
                	}
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){
                	result='0';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	HKEYPAD_VidDelay();
                }
                break;
       }

       case 2:{

                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){
                	result='9';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
                	HKEYPAD_VidDelay();
                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){
                	result='6';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                	HKEYPAD_VidDelay();
                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){
                	result='3';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                	HKEYPAD_VidDelay();
                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){
                	result='=';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	HKEYPAD_VidDelay();
                }
                break;

       }


    case 3:{

                if     (MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0){
                	result='/';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C0)==0);
                	HKEYPAD_VidDelay();
                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0){
                	result='*';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C1)==0);
                	HKEYPAD_VidDelay();
                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0){
                	result='-';
                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C2)==0);
                	HKEYPAD_VidDelay();
                }
                else if(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0){
                	result='+';

                	while(MGPIO_u8GetPinValue(HKEYPAD_PORT,C3)==0);
                	HKEYPAD_VidDelay();
                }
                break;
    		}
       }
    }
return result;
}*/
