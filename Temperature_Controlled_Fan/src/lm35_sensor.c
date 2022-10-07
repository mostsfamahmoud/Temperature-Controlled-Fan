/*
 * Module: LM35 Temperature Sensor
 *
 * File Name: lm35_sensor.c
 *
 * Description: Source file for the LM35 Temperature Sensor driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/

#include "lm35_sensor.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/


/* Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void)
{
	uint8 tempValue = 0;

	uint16 adcValue = 0;

	adcValue = ADC_readChannel(SENSOR_CHANNEL_ID);

	tempValue = (uint8) (((float32) adcValue * ADC_REF_VOLT_VALUE * SENSOR_MAX_TEMPERATURE)/(SENSOR_MAX_VOLTAGE * ADC_MAXIMUM_VALUE));

	return tempValue;
}


