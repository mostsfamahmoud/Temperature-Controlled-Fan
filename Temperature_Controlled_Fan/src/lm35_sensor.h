/*
 * Module: LM35 Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: Header file for the LM35 Temperature Sensor driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "adc.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_MAX_TEMPERATURE   150
#define SENSOR_MAX_VOLTAGE       1.5
#define SENSOR_CHANNEL_ID        2


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void);

#endif /* LM35_SENSOR_H_ */
