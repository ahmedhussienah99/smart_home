

#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SPI_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"

int main ( void ){
	u8 LOC_u8NewData;
	char x=0xff;
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOB_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , SPI1_RCC  );
	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC                  ) ;


/*
	MGPIO_VidSetPinDirection( GPIOB , PIN5 , OUTPUT_SPEED_2MHZ_AFPP );//MOSI
	MGPIO_VidSetPinDirection( GPIOB , PIN4 , INPUT_FLOATING );//MISO

	MGPIO_VidSetPinDirection( GPIOB , PIN3 , OUTPUT_SPEED_2MHZ_AFPP );//CLOCK
	MGPIO_VidSetPinDirection( GPIOA , PIN15 , OUTPUT_SPEED_2MHZ_AFPP );

	MGPIO_VidSetPinDirection(GPIOB,0,OUTPUT_SPEED_2MHZ_PP);*/
	MGPIO_VidSetPinDirection( GPIOA , PIN9 , OUTPUT_SPEED_2MHZ_AFPP );
	//MSPI_VidInit();
	MUSART_VidInit();

	HLCD_VidInit();
	HKEYPAD_VidInit();
	u8 room;
	u8 control;
	u8 on_off;
	u8 first=0;
	HLCD_VidClearScreen();
	HLCD_VidWriteString("HelloSmartHOME");
	main_VidDelay();
	HLCD_VidClearScreen();
	while(1){
	if(first==0){
		HLCD_VidClearScreen();
	HLCD_VidWriteString("Choos ur Mode:");

	HLCD_VidShift(1,2);
	HLCD_VidWriteString("Admin0:");
	HLCD_VidShift(8,2);
	HLCD_VidWriteString("Guset1:");
	first=1;
	}

	HKEYPAD_VidDelay();
	HKEYPAD_VidDelay();
	x=HkEYPAD_u8GetPress();

	if(x=='0'){		//choose admin mode
		x=6;
		first=0;
		HLCD_VidClearScreen();
	while(1){

			if(first==0){
				HLCD_VidClearScreen();
			HLCD_VidWriteString("WelcomeADMINMode:");
			main_VidDelay();
			HLCD_VidClearScreen();
			HLCD_VidWriteString("Control Room: ");
			HLCD_VidShift(15,1);
			HLCD_VidWriteString("<-");
			HLCD_VidShift(16,2);
			HLCD_VidWriteString("5");
			HLCD_VidShift(1,2);
			HLCD_VidWriteString("Room(1/2/3/4:");
			first=1;
			}
			HKEYPAD_VidDelay();
			HKEYPAD_VidDelay();
			room=HkEYPAD_u8GetPress();
			if(room=='5'){first=0;	room=6; break;}
			else if(room=='1'){
				room=6;
				first=0;
				HLCD_VidClearScreen();
			while(1){
						if(first==0){
						//room=0;
						HLCD_VidClearScreen();
						HLCD_VidWriteString("Welcome Room1:");
						HLCD_VidShift(15,1);
									HLCD_VidWriteString("<-");
									HLCD_VidShift(16,2);
									HLCD_VidWriteString("5");
						HLCD_VidShift(1,2);
						HLCD_VidWriteString("LI1/AIR2/TV3:");
						first=1;
						}
						HKEYPAD_VidDelay();
						HKEYPAD_VidDelay();
						control=HkEYPAD_u8GetPress();
						if(control=='5'){first=0;	control=6; break;}
						else if(control=='1'){
							control=6;
							first=0;
							HLCD_VidClearScreen();
						while(1){

								if(first==0){
								//control=0;
									HLCD_VidClearScreen();
								HLCD_VidWriteString("LI-ON1/OFF0:");
								HLCD_VidShift(15,1);
											HLCD_VidWriteString("<-");
											HLCD_VidShift(16,2);
											HLCD_VidWriteString("5");
								first=1;
								}
								HKEYPAD_VidDelay();
								HKEYPAD_VidDelay();
								on_off=HkEYPAD_u8GetPress();
								 if(on_off=='5'){first=0;on_off=6; break;}
								 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
								 HLCD_VidShift(15,1);
								 			HLCD_VidWriteString("<-");
								 			HLCD_VidShift(16,2);
								 			HLCD_VidWriteString("5");
								  MUSART1_VidSendCharSync('1');
								 HKEYPAD_VidDelay();
								HKEYPAD_VidDelay();
															}
								 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
								 HLCD_VidShift(15,1);
								 			HLCD_VidWriteString("<-");
								 			HLCD_VidShift(16,2);
								 			HLCD_VidWriteString("5");
								MUSART1_VidSendCharSync('0');
								HKEYPAD_VidDelay();
								HKEYPAD_VidDelay();
														}

							}
						}
						else if(control=='2'){
												control=6;
												first=0;
												HLCD_VidClearScreen();
											while(1){

													if(first==0){
													//control=0;
													HLCD_VidWriteString("AIR ON1/OFF0:");
													HLCD_VidShift(15,1);
																HLCD_VidWriteString("<-");
																HLCD_VidShift(16,2);
																HLCD_VidWriteString("5");
													first=1;
													}
													HKEYPAD_VidDelay();
													on_off=HkEYPAD_u8GetPress();
													 if(on_off=='5'){first=0;on_off=6; break;}
													 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
													 HLCD_VidShift(15,1);
													 			HLCD_VidWriteString("<-");
													 			HLCD_VidShift(16,2);
													 			HLCD_VidWriteString("5");
													  MUSART1_VidSendCharSync('3');
													 HKEYPAD_VidDelay();
													HKEYPAD_VidDelay();
																				}
													 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
													 HLCD_VidShift(15,1);
													 			HLCD_VidWriteString("<-");
													 			HLCD_VidShift(16,2);
													 			HLCD_VidWriteString("5");
													MUSART1_VidSendCharSync('4');
													HKEYPAD_VidDelay();
													HKEYPAD_VidDelay();
																			}

												}
											}
						else if(control=='3'){
												control=6;
												first=0;
												HLCD_VidClearScreen();
											while(1){

													if(first==0){
													//control=0;
													HLCD_VidWriteString("TV-ON1/OFF0:");
													HLCD_VidShift(15,1);
																HLCD_VidWriteString("<-");
																HLCD_VidShift(16,2);
																HLCD_VidWriteString("5");
													first=1;
													}
													HKEYPAD_VidDelay();
													on_off=HkEYPAD_u8GetPress();
													 if(on_off=='5'){first=0;on_off=6; break;}
													 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
													 HLCD_VidShift(15,1);
													 			HLCD_VidWriteString("<-");
													 			HLCD_VidShift(16,2);
													 			HLCD_VidWriteString("5");
													  MUSART1_VidSendCharSync('5');
													 HKEYPAD_VidDelay();
													HKEYPAD_VidDelay();
																				}
													 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
													 HLCD_VidShift(15,1);
													 			HLCD_VidWriteString("<-");
													 			HLCD_VidShift(16,2);
													 			HLCD_VidWriteString("5");
													MUSART1_VidSendCharSync('6');
													HKEYPAD_VidDelay();
													HKEYPAD_VidDelay();
																			}

												}
											}


					}
				}
			else if(room=='2'){
							room=6;
							first=0;
							HLCD_VidClearScreen();
						while(1){
									if(first==0){
									//room=0;
									HLCD_VidClearScreen();
									HLCD_VidWriteString("Welcome Room2:");
									HLCD_VidShift(15,1);
												HLCD_VidWriteString("<-");
												HLCD_VidShift(16,2);
												HLCD_VidWriteString("5");
									HLCD_VidShift(1,2);
									HLCD_VidWriteString("LI1/AIR2/TV3:");
									first=1;
									}
									HKEYPAD_VidDelay();
									HKEYPAD_VidDelay();
									control=HkEYPAD_u8GetPress();
									if(control=='5'){first=0;	control=6; break;}
									else if(control=='1'){
										control=6;
										first=0;
										HLCD_VidClearScreen();
									while(1){

											if(first==0){
											//control=0;
												HLCD_VidClearScreen();
											HLCD_VidWriteString("LI-ON1/OFF0:");
											HLCD_VidShift(15,1);
														HLCD_VidWriteString("<-");
														HLCD_VidShift(16,2);
														HLCD_VidWriteString("5");
											first=1;
											}
											HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
											on_off=HkEYPAD_u8GetPress();
											 if(on_off=='5'){first=0;on_off=6; break;}
											 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
											 HLCD_VidShift(15,1);
											 			HLCD_VidWriteString("<-");
											 			HLCD_VidShift(16,2);
											 			HLCD_VidWriteString("5");
											  MUSART1_VidSendCharSync('1');
											 HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
																		}
											 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
											 HLCD_VidShift(15,1);
											 			HLCD_VidWriteString("<-");
											 			HLCD_VidShift(16,2);
											 			HLCD_VidWriteString("5");
											MUSART1_VidSendCharSync('0');
											HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
																	}

										}
									}
									else if(control=='2'){
															control=6;
															first=0;
															HLCD_VidClearScreen();
														while(1){

																if(first==0){
																//control=0;
																HLCD_VidWriteString("AIR ON1/OFF0:");
																HLCD_VidShift(15,1);
																			HLCD_VidWriteString("<-");
																			HLCD_VidShift(16,2);
																			HLCD_VidWriteString("5");
																first=1;
																}
																HKEYPAD_VidDelay();
																on_off=HkEYPAD_u8GetPress();
																 if(on_off=='5'){first=0;on_off=6; break;}
																 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																  MUSART1_VidSendCharSync('3');
																 HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																							}
																 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																MUSART1_VidSendCharSync('4');
																HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																						}

															}
														}
									else if(control=='3'){
															control=6;
															first=0;
															HLCD_VidClearScreen();
														while(1){

																if(first==0){
																//control=0;
																HLCD_VidWriteString("TV-ON1/OFF0:");
																HLCD_VidShift(15,1);
																			HLCD_VidWriteString("<-");
																			HLCD_VidShift(16,2);
																			HLCD_VidWriteString("5");
																first=1;
																}
																HKEYPAD_VidDelay();
																on_off=HkEYPAD_u8GetPress();
																 if(on_off=='5'){first=0;on_off=6; break;}
																 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																  MUSART1_VidSendCharSync('5');
																 HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																							}
																 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																MUSART1_VidSendCharSync('6');
																HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																						}

															}
														}


								}
							}
			else if(room=='3'){
							room=6;
							first=0;
							HLCD_VidClearScreen();
						while(1){
									if(first==0){
									//room=0;
									HLCD_VidClearScreen();
									HLCD_VidWriteString("Welcome Room3:");
									HLCD_VidShift(15,1);
												HLCD_VidWriteString("<-");
												HLCD_VidShift(16,2);
												HLCD_VidWriteString("5");
									HLCD_VidShift(1,2);
									HLCD_VidWriteString("LI1/AIR2/TV3:");
									first=1;
									}
									HKEYPAD_VidDelay();
									HKEYPAD_VidDelay();
									control=HkEYPAD_u8GetPress();
									if(control=='5'){first=0;	control=6; break;}
									else if(control=='1'){
										control=6;
										first=0;
										HLCD_VidClearScreen();
									while(1){

											if(first==0){
											//control=0;
												HLCD_VidClearScreen();
											HLCD_VidWriteString("LI-ON1/OFF0:");
											HLCD_VidShift(15,1);
														HLCD_VidWriteString("<-");
														HLCD_VidShift(16,2);
														HLCD_VidWriteString("5");
											first=1;
											}
											HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
											on_off=HkEYPAD_u8GetPress();
											 if(on_off=='5'){first=0;on_off=6; break;}
											 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
											 HLCD_VidShift(15,1);
											 			HLCD_VidWriteString("<-");
											 			HLCD_VidShift(16,2);
											 			HLCD_VidWriteString("5");
											  MUSART1_VidSendCharSync('1');
											 HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
																		}
											 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
											 HLCD_VidShift(15,1);
											 			HLCD_VidWriteString("<-");
											 			HLCD_VidShift(16,2);
											 			HLCD_VidWriteString("5");
											MUSART1_VidSendCharSync('0');
											HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
																	}

										}
									}
									else if(control=='2'){
															control=6;
															first=0;
															HLCD_VidClearScreen();
														while(1){

																if(first==0){
																//control=0;
																HLCD_VidWriteString("AIR ON1/OFF0:");
																HLCD_VidShift(15,1);
																			HLCD_VidWriteString("<-");
																			HLCD_VidShift(16,2);
																			HLCD_VidWriteString("5");
																first=1;
																}
																HKEYPAD_VidDelay();
																on_off=HkEYPAD_u8GetPress();
																 if(on_off=='5'){first=0;on_off=6; break;}
																 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																  MUSART1_VidSendCharSync('3');
																 HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																							}
																 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																MUSART1_VidSendCharSync('4');
																HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																						}

															}
														}
									else if(control=='3'){
															control=6;
															first=0;
															HLCD_VidClearScreen();
														while(1){

																if(first==0){
																//control=0;
																HLCD_VidWriteString("TV-ON1/OFF0:");
																HLCD_VidShift(15,1);
																			HLCD_VidWriteString("<-");
																			HLCD_VidShift(16,2);
																			HLCD_VidWriteString("5");
																first=1;
																}
																HKEYPAD_VidDelay();
																on_off=HkEYPAD_u8GetPress();
																 if(on_off=='5'){first=0;on_off=6; break;}
																 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																  MUSART1_VidSendCharSync('5');
																 HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																							}
																 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																MUSART1_VidSendCharSync('6');
																HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																						}

															}
														}


								}
							}
			else if(room=='4'){
							room=6;
							first=0;
							HLCD_VidClearScreen();
						while(1){
									if(first==0){
									//room=0;
									HLCD_VidClearScreen();
									HLCD_VidWriteString("Welcome Room4:");
									HLCD_VidShift(15,1);
												HLCD_VidWriteString("<-");
												HLCD_VidShift(16,2);
												HLCD_VidWriteString("5");
									HLCD_VidShift(1,2);
									HLCD_VidWriteString("LI1/AIR2/TV3:");
									first=1;
									}
									HKEYPAD_VidDelay();
									HKEYPAD_VidDelay();
									control=HkEYPAD_u8GetPress();
									if(control=='5'){first=0;	control=6; break;}
									else if(control=='1'){
										control=6;
										first=0;
										HLCD_VidClearScreen();
									while(1){

											if(first==0){
											//control=0;
												HLCD_VidClearScreen();
											HLCD_VidWriteString("LI-ON1/OFF0:");
											HLCD_VidShift(15,1);
														HLCD_VidWriteString("<-");
														HLCD_VidShift(16,2);
														HLCD_VidWriteString("5");
											first=1;
											}
											HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
											on_off=HkEYPAD_u8GetPress();
											 if(on_off=='5'){first=0;on_off=6; break;}
											 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
											 HLCD_VidShift(15,1);
											 			HLCD_VidWriteString("<-");
											 			HLCD_VidShift(16,2);
											 			HLCD_VidWriteString("5");
											  MUSART1_VidSendCharSync('1');
											 HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
																		}
											 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
											 HLCD_VidShift(15,1);
											 			HLCD_VidWriteString("<-");
											 			HLCD_VidShift(16,2);
											 			HLCD_VidWriteString("5");
											MUSART1_VidSendCharSync('0');
											HKEYPAD_VidDelay();
											HKEYPAD_VidDelay();
																	}

										}
									}
									else if(control=='2'){
															control=6;
															first=0;
															HLCD_VidClearScreen();
														while(1){

																if(first==0){
																//control=0;
																HLCD_VidWriteString("AIR ON1/OFF0:");
																HLCD_VidShift(15,1);
																			HLCD_VidWriteString("<-");
																			HLCD_VidShift(16,2);
																			HLCD_VidWriteString("5");
																first=1;
																}
																HKEYPAD_VidDelay();
																on_off=HkEYPAD_u8GetPress();
																 if(on_off=='5'){first=0;on_off=6; break;}
																 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																  MUSART1_VidSendCharSync('3');
																 HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																							}
																 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																MUSART1_VidSendCharSync('4');
																HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																						}

															}
														}
									else if(control=='3'){
															control=6;
															first=0;
															HLCD_VidClearScreen();
														while(1){

																if(first==0){
																//control=0;
																HLCD_VidWriteString("TV-ON1/OFF0:");
																HLCD_VidShift(15,1);
																			HLCD_VidWriteString("<-");
																			HLCD_VidShift(16,2);
																			HLCD_VidWriteString("5");
																first=1;
																}
																HKEYPAD_VidDelay();
																on_off=HkEYPAD_u8GetPress();
																 if(on_off=='5'){first=0;on_off=6; break;}
																 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																  MUSART1_VidSendCharSync('5');
																 HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																							}
																 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
																 HLCD_VidShift(15,1);
																 			HLCD_VidWriteString("<-");
																 			HLCD_VidShift(16,2);
																 			HLCD_VidWriteString("5");
																MUSART1_VidSendCharSync('6');
																HKEYPAD_VidDelay();
																HKEYPAD_VidDelay();
																						}

															}
														}


								}
							}













			}
		}
	else if(x=='1'){		//choose admin mode
			x=6;
			first=0;
			HLCD_VidClearScreen();
		while(1){

				if(first==0){
					HLCD_VidClearScreen();
				HLCD_VidWriteString("WelcomeGuestMode:");
				main_VidDelay();
				HLCD_VidClearScreen();
				HLCD_VidWriteString("Control Room: ");
				HLCD_VidShift(15,1);
							HLCD_VidWriteString("<-");
							HLCD_VidShift(16,2);
							HLCD_VidWriteString("5");
				HLCD_VidShift(1,2);
				HLCD_VidWriteString("Room(1/2/3/4:");
				first=1;
				}
				HKEYPAD_VidDelay();
				HKEYPAD_VidDelay();
				room=HkEYPAD_u8GetPress();
				if(room=='5'){first=0;	room=6; break;}
				else if(room=='1'){
					room=6;
					first=0;
					HLCD_VidClearScreen();
				while(1){
							if(first==0){
							//room=0;
							HLCD_VidClearScreen();
							HLCD_VidWriteString("Welcome Room1:");
							HLCD_VidShift(15,1);
										HLCD_VidWriteString("<-");
										HLCD_VidShift(16,2);
										HLCD_VidWriteString("5");
							HLCD_VidShift(1,2);
							HLCD_VidWriteString("LIGHT1:");
							first=1;
							}
							HKEYPAD_VidDelay();
							HKEYPAD_VidDelay();
							control=HkEYPAD_u8GetPress();
							if(control=='5'){first=0;	control=6; break;}
							else if(control=='1'){
								control=6;
								first=0;
								HLCD_VidClearScreen();
							while(1){

									if(first==0){
									//control=0;
										HLCD_VidClearScreen();
									HLCD_VidWriteString("LI-ON1/OFF0:");
									HLCD_VidShift(15,1);
												HLCD_VidWriteString("<-");
												HLCD_VidShift(16,2);
												HLCD_VidWriteString("5");
									first=1;
									}
									HKEYPAD_VidDelay();
									HKEYPAD_VidDelay();
									on_off=HkEYPAD_u8GetPress();
									 if(on_off=='5'){first=0;on_off=6; break;}
									 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
									 HLCD_VidShift(15,1);
									 			HLCD_VidWriteString("<-");
									 			HLCD_VidShift(16,2);
									 			HLCD_VidWriteString("5");
									  MUSART1_VidSendCharSync('1');
									 HKEYPAD_VidDelay();
									HKEYPAD_VidDelay();
																}
									 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
									 HLCD_VidShift(15,1);
									 			HLCD_VidWriteString("<-");
									 			HLCD_VidShift(16,2);
									 			HLCD_VidWriteString("5");
									MUSART1_VidSendCharSync('0');
									HKEYPAD_VidDelay();
									HKEYPAD_VidDelay();
															}

								}
							}

						}
					}
				else if(room=='2'){
								room=6;
								first=0;
								HLCD_VidClearScreen();
							while(1){
										if(first==0){
										//room=0;
										HLCD_VidClearScreen();
										HLCD_VidWriteString("Welcome Room2:");
										HLCD_VidShift(15,1);
													HLCD_VidWriteString("<-");
													HLCD_VidShift(16,2);
													HLCD_VidWriteString("5");
										HLCD_VidShift(1,2);
										HLCD_VidWriteString("LIGHT1:");
										first=1;
										}
										HKEYPAD_VidDelay();
										HKEYPAD_VidDelay();
										control=HkEYPAD_u8GetPress();
										if(control=='5'){first=0;	control=6; break;}
										else if(control=='1'){
											control=6;
											first=0;
											HLCD_VidClearScreen();
										while(1){

												if(first==0){
												//control=0;
													HLCD_VidClearScreen();
												HLCD_VidWriteString("LI-ON1/OFF0:");
												HLCD_VidShift(15,1);
															HLCD_VidWriteString("<-");
															HLCD_VidShift(16,2);
															HLCD_VidWriteString("5");
												first=1;
												}
												HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
												on_off=HkEYPAD_u8GetPress();
												 if(on_off=='5'){first=0;on_off=6; break;}
												 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
												 HLCD_VidShift(15,1);
												 			HLCD_VidWriteString("<-");
												 			HLCD_VidShift(16,2);
												 			HLCD_VidWriteString("5");
												  MUSART1_VidSendCharSync('1');
												 HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
																			}
												 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
												 HLCD_VidShift(15,1);
												 			HLCD_VidWriteString("<-");
												 			HLCD_VidShift(16,2);
												 			HLCD_VidWriteString("5");
												MUSART1_VidSendCharSync('0');
												HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
																		}

											}
										}


									}
								}
				else if(room=='3'){
								room=6;
								first=0;
								HLCD_VidClearScreen();
							while(1){
										if(first==0){
										//room=0;
										HLCD_VidClearScreen();
										HLCD_VidWriteString("Welcome Room3:");
										HLCD_VidShift(15,1);
													HLCD_VidWriteString("<-");
													HLCD_VidShift(16,2);
													HLCD_VidWriteString("5");
										HLCD_VidShift(1,2);
										HLCD_VidWriteString("LIGHT1:");
										first=1;
										}
										HKEYPAD_VidDelay();
										HKEYPAD_VidDelay();
										control=HkEYPAD_u8GetPress();
										if(control=='5'){first=0;	control=6; break;}
										else if(control=='1'){
											control=6;
											first=0;
											HLCD_VidClearScreen();
										while(1){

												if(first==0){
												//control=0;
													HLCD_VidClearScreen();
												HLCD_VidWriteString("LI-ON1/OFF0:");
												HLCD_VidShift(15,1);
															HLCD_VidWriteString("<-");
															HLCD_VidShift(16,2);
															HLCD_VidWriteString("5");
												first=1;
												}
												HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
												on_off=HkEYPAD_u8GetPress();
												 if(on_off=='5'){first=0;on_off=6; break;}
												 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
												 HLCD_VidShift(15,1);
												 			HLCD_VidWriteString("<-");
												 			HLCD_VidShift(16,2);
												 			HLCD_VidWriteString("5");
												  MUSART1_VidSendCharSync('1');
												 HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
																			}
												 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
												 HLCD_VidShift(15,1);
												 			HLCD_VidWriteString("<-");
												 			HLCD_VidShift(16,2);
												 			HLCD_VidWriteString("5");
												MUSART1_VidSendCharSync('0');
												HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
																		}

											}
										}


									}
								}
				else if(room=='4'){
								room=6;
								first=0;
								HLCD_VidClearScreen();
							while(1){
										if(first==0){
										//room=0;
										HLCD_VidClearScreen();
										HLCD_VidWriteString("Welcome Room4:");
										HLCD_VidShift(15,1);
													HLCD_VidWriteString("<-");
													HLCD_VidShift(16,2);
													HLCD_VidWriteString("5");
										HLCD_VidShift(1,2);
										HLCD_VidWriteString("LIGHT1:");
										first=1;
										}
										HKEYPAD_VidDelay();
										HKEYPAD_VidDelay();
										control=HkEYPAD_u8GetPress();
										if(control=='5'){first=0;	control=6; break;}
										else if(control=='1'){
											control=6;
											first=0;
											HLCD_VidClearScreen();
										while(1){

												if(first==0){
												//control=0;
													HLCD_VidClearScreen();
												HLCD_VidWriteString("LI-ON1/OFF0:");
												HLCD_VidShift(15,1);
															HLCD_VidWriteString("<-");
															HLCD_VidShift(16,2);
															HLCD_VidWriteString("5");
												first=1;
												}
												HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
												on_off=HkEYPAD_u8GetPress();
												 if(on_off=='5'){first=0;on_off=6; break;}
												 else if(on_off=='1'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("ON");
												 HLCD_VidShift(15,1);
												 			HLCD_VidWriteString("<-");
												 			HLCD_VidShift(16,2);
												 			HLCD_VidWriteString("5");
												  MUSART1_VidSendCharSync('1');
												 HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
																			}
												 else if(on_off=='0'){on_off=6;HLCD_VidClearScreen();HLCD_VidWriteString("OFF");
												 HLCD_VidShift(15,1);
												 			HLCD_VidWriteString("<-");
												 			HLCD_VidShift(16,2);
												 			HLCD_VidWriteString("5");
												MUSART1_VidSendCharSync('0');
												HKEYPAD_VidDelay();
												HKEYPAD_VidDelay();
																		}

											}
										}

									}
								}













				}
			}
	}




	return 0 ;
}
