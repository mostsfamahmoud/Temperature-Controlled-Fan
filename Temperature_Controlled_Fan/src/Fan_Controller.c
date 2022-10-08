/******************************************************************************
 *
 * Module: Application(Temperature-Controlled Fan)
 *
 * File Name: Fan_Controller.c
 *
 * Description: Project main Source file for Temperature-Controlled Fan
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/

#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"


int main(void)
{
	uint8 tempValue = 0;               /* Variable to Store the Temperature value (initialized with 0) */

	ADC_ConfigType *Config_Ptr;        /* Pointer to Struct of type ADC_ConfigType */

	Config_Ptr->prescaler = FCPU_8;       /* Make ADC operate with Frequency = FCPU/8 (Prescaler --> 8) */

	Config_Ptr->ref_volt = INTERNAL_VREF; /* Make ADC operate with the internal reference voltage (2.56 V) */

	ADC_init(Config_Ptr);     /* Passing this Pointer as Parameter to ADC_init() to initailize ADC with these requirements */

	LCD_init();               /* Initialize LCD */

	DcMotor_Init();           /* Initialize DC-Motor */

	LCD_displayStringRowColumn(0, 2, "FAN IS ");     /* Display String "FAN IS" at (ROW 0, COLUMN 2) on LCD */
	LCD_displayStringRowColumn(1, 2, "TEMP = ");    /* Display String "TEMP = " at (ROW 1, COLUMN 2) on LCD */


	while(1)
	{
		tempValue = LM35_GetTemperature();    /* Get the value of Temperature from LM35 Sensor */

		/*  If the temperature is less than 30 C, Turn off the fan */
		if (tempValue < 30)
			LCD_displayStringRowColumn(0, 9,"OFF");
		else
		{
			LCD_displayStringRowColumn(0, 9,"ON");
			/* To Clear the next digit if OFF state happened first */
			LCD_displayCharacter(' ');
		}


		LCD_moveCursor(1, 9);              /* Move Cursor to (ROW 1 , COLUMN 9) on LCD */
		LCD_integerToString(tempValue);    /* Convert Temperature's Decimal value into String to Display it on LCD */

		/* To handle the transitions of the digital value from 3 digits to 2 or 1 , Print space in the next digit place */
		LCD_displayString(" C ");


		if(tempValue >= 120)
		{
			/* If the temperature is greater than or equal 120C , Turn on the fan with 100% of its maximum speed */
			DcMotor_Rotate(ClockWise, 100);
		}
		else if(tempValue >= 90)
		{
			/* If the temperature is greater than or equal 90C , Turn on the fan with 75% of its maximum speed */
			DcMotor_Rotate(ClockWise, 75);
		}
		else if(tempValue >= 60)
		{
			/* If the temperature is greater than or equal 60C , Turn on the fan with 50% of its maximum speed */
			DcMotor_Rotate(ClockWise, 50);
		}
		else if (tempValue >= 30)
		{
			/* If the temperature is greater than or equal 30C , Turn on the fan with 25% of its maximum speed */
			DcMotor_Rotate(ClockWise, 25);
		}
		else
		{
			/* If the temperature is less than 30 C, Turn off the fan
			 * With DC_MotorState = STOP , To Stop the Motion of DC-Motor (Fan OFF)
			 * Speed MUST be ZERO , To Make OCR0 = ZERO --> NO PWM Signal (NO Speed)
 			 */
			DcMotor_Rotate(STOP, 0);
		}
	}

}


