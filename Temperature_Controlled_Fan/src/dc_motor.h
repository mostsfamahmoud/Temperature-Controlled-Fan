 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the DC MOTOR driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR_PINS_PORT_ID         PORTB_ID

#define MOTOR_IN1_PIN_ID           PIN0_ID
#define MOTOR_IN2_PIN_ID           PIN1_ID


/* Enum DcMotor_State to Select type of motion of DC-Motor (CW, A_CW, Stop) */
typedef enum{
	STOP,Anti_ClockWise,ClockWise
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
Description
	1) The Function responsible for setup the direction for the two motor pins through the GPIO driver.
	2) Stop at the DC-Motor at the beginning through the GPIO driver.
*/
void DcMotor_Init(void);


/*
Description:
	1) The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.

	2) Send the required duty cycle to the PWM driver based on the required speed value.

Inputs:
	1) State: The required DC Motor state, it should be CW or A-CW or stop.
	          DcMotor_State data type should be declared as enum or uint8.

	2) Speed: decimal value for the required motor speed, it should be from 0 → 100.
	          For example, if the input is 50, The motor should rotate with 50% of its maximum speed.

Return: None
*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
