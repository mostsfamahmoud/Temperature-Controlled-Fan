 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.C
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/

#include "adc.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/


/*
 * Description:
 *     Function responsible for initialize the ADC driver.
 * Inputs:
 *     Pointer to Constant Struct of type (ADC_ConfigType) to dynamically configure Ref_Volt & Prescaler of ADC
 * Return:
 *     None
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 -> Dynamically chosen by user according to Config_Ptr->ref_volt
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */

	ADMUX = (Config_Ptr->ref_volt << 6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt (Polling Mode)
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 -> Dynamically chosen by user to select ADC_Clock according to Config_Ptr->prescaler
	 *            ADC must operate in range 50-200Khz
	 */

	ADCSRA = (1 << ADEN) | (Config_Ptr->prescaler & 0x07);
}


/*
 * Description:
 *      Function responsible for read analog data from a certain ADC channel and convert it to digital using the ADC driver.
 * Inputs:
 *      Variable (channel_num) of type enum (ADC_Channel_ID)
 * Return:
 *      The digital value represented by (10 Bits) that is made by converting the Analog using ADC
 */
uint16 ADC_readChannel(ADC_Channel_ID channel_num)
{
	/* 1) Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel)
	 * 2) Input channel number must be from 0 --> 7
	 * 3) Choose the correct channel by setting the channel number in MUX4:0 bits
	 */
	ADMUX = (ADMUX &= 0xE0) | (channel_num & 0x07);

	SET_BIT(ADCSRA,ADSC);              /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));  /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF);              /* Clear ADIF by writing '1' to it */
	return ADC;                        /* Read the digital value from the data register */
}


