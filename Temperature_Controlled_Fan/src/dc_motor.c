 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the DC MOTOR driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/


#include "dc_motor.h"
#include "pwm.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/


/*
Description
	1) The Function responsible for setup the direction for the two motor pins through the GPIO driver.

	2) Stop at the DC-Motor at the beginning through the GPIO driver.

Inputs: None

Return: None
*/
void DcMotor_Init(void)
{
	/* Configure Pins PB0 and PB1 as Output pins */
	GPIO_setupPinDirection(MOTOR_PINS_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PINS_PORT_ID, MOTOR_IN2_PIN_ID, PIN_OUTPUT);

	/* Stop the DC-Motor at the beginning (IN1 = 0, IN2 = 0) */
	GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
}


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
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/* Setting the DC Motor rotation direction (CW/ or A-CW or stop) based on the state value. */
	switch(state)
	{
	case STOP:
		/* Stop the DC-Motor (IN1 = 0, IN2 = 0) */
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case ClockWise:
		/* DC-Motor Mode --> ClockWise Rotation (IN1 = 0, IN2 = 1) */
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case Anti_ClockWise:
		/* DC-Motor Mode --> Anti_ClockWise Rotation (IN1 = 1, IN2 = 0) */
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	default:
		break;
	}

	/* Setting the Required DC Motor Speed Using PWM Signal at Enable1 */
	if ((speed > 0) && (speed <= 100))
	{
		PWM_Timer0_Start(speed);
	}
	else
	{
		/* Stop the DC-Motor when Speed is out of Range (IN1 = 0, IN2 = 0) */
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PINS_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	}
}
