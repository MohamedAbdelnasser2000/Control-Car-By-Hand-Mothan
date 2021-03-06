/*
 * Motor_Interface.c
 *
 * Created: 26/3/2022 10:41:47 PM
 *  Author: Omar
 */ 
#include "Motor_Private.h"

void Motor_Initialize(void){
	DIO_SetPinDirection(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, H_BRIDGE_STATE);
	DIO_SetPinDirection(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, H_BRIDGE_STATE);
	DIO_SetPinDirection(H_BRIDGE_A_PRT, H_BRIDGE_A1, H_BRIDGE_STATE);
	DIO_SetPinDirection(H_BRIDGE_A_PRT, H_BRIDGE_A2, H_BRIDGE_STATE);
	DIO_SetPinDirection(H_BRIDGE_A_PRT, H_BRIDGE_A3, H_BRIDGE_STATE);
	DIO_SetPinDirection(H_BRIDGE_A_PRT, H_BRIDGE_A4, H_BRIDGE_STATE);
}
void Motor_ON(motor_direction direction, motor_enable enable_pin){
	if(enable_pin == enable1){
		if(direction == clockwise){
			DIO_SetPinValue(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, DIO_HIGH);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A1, DIO_HIGH);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A2, DIO_LOW);
		}
		else if(direction == anticlockwise){
			DIO_SetPinValue(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, DIO_HIGH);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A1, DIO_LOW);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A2, DIO_HIGH);
		}
	}
	else if(enable_pin == enable2){
		if(direction == clockwise){
			DIO_SetPinValue(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, DIO_HIGH);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A3, DIO_HIGH);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A4, DIO_LOW);
		}
		else if(direction == anticlockwise){
			DIO_SetPinValue(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, DIO_HIGH);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A3, DIO_LOW);
			DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A4, DIO_HIGH);
		}
	}
}
void Motor_OFF(motor_enable enable_pin){
	if(enable_pin == enable1){
		DIO_SetPinValue(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, DIO_LOW);
		DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A1, DIO_LOW);
		DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A2, DIO_LOW);
	}
	else if(enable_pin == enable1){
		DIO_SetPinValue(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, DIO_LOW);
		DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A3, DIO_LOW);
		DIO_SetPinValue(H_BRIDGE_A_PRT, H_BRIDGE_A4, DIO_LOW);
	}
	
}