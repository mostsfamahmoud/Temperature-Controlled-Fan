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
	uint8 tempValue = 0;

	ADC_ConfigType *Config_Ptr;

	Config_Ptr->prescaler = FCPU_8;
	Config_Ptr->ref_volt = INTERNAL_VREF;

	ADC_init(Config_Ptr);

	LCD_init();

	DcMotor_Init();

	LCD_displayStringRowColumn(0, 2, "FAN IS ");
	LCD_displayStringRowColumn(1, 2, "TEMP = ");


	while(1)
	{
		tempValue = LM35_GetTemperature();

		if (tempValue < 30)
			LCD_displayStringRowColumn(0, 9,"OFF");
		else
		{
			LCD_displayStringRowColumn(0, 9,"ON");
			LCD_displayCharacter(' ');
		}


		LCD_moveCursor(1, 9);
		LCD_integerToString(tempValue);
		LCD_displayString(" C ");

		if(tempValue >= 120)
		{
			DcMotor_Rotate(ClockWise, 100);
		}
		else if(tempValue >= 90)
		{
			DcMotor_Rotate(ClockWise, 75);
		}
		else if(tempValue >= 60)
		{
			DcMotor_Rotate(ClockWise, 50);
		}
		else if (tempValue >= 30)
		{
			DcMotor_Rotate(ClockWise, 25);
		}
		else
		{
			DcMotor_Rotate(STOP, 0);
		}
	}

}


