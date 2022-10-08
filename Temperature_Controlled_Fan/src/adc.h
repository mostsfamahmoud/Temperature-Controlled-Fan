 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "Macros.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE     1023
#define ADC_REF_VOLT_VALUE    2.56


/* Enum ADC_ReferenceVoltage to select the Reference Voltage of the ADC */
typedef enum{
	AREF,AVCC,RESERVED,INTERNAL_VREF
}ADC_ReferenceVoltage;

/* Enum ADC_Prescaler to select the divison factor between F_CPU and F_ADC */
typedef enum{
	FCPU_2,FCPU_4 = 2,FCPU_8,FCPU_16,FCPU_32,FCPU_64,FCPU_128
}ADC_Prescaler;

/* Enum ADC_Channel_ID to select which ADC Channel (0 --> 7) will be used */
typedef enum{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ADC_Channel_ID;

/* Struct ADC_ConfigType to make ADC driver Configurable by selecting the suitable Reference Voltage & Prescaler */
typedef struct{
 ADC_ReferenceVoltage ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 *     Function responsible for initialize the ADC driver.
 * Inputs:
 *     Pointer to Constant Struct of type (ADC_ConfigType) to dynamically configure Ref_Volt & Prescaler of ADC
 * Return:
 *     None
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description:
 *      Function responsible for read analog data from a certain ADC channel and convert it to digital using the ADC driver.
 * Inputs:
 *      Variable (channel_num) of type enum (ADC_Channel_ID)
 * Return:
 *      The digital value that is converted by ADC
 */
uint16 ADC_readChannel(ADC_Channel_ID channel_num);



#endif /* ADC_H_ */
