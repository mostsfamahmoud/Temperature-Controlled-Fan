 /******************************************************************************
 *
 * Module: PWM_TIMER0
 *
 * File Name: pwm.h
 *
 * Description: header file for the AVR PWM_TIMER0 driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_

#include "gpio.h"

#define OC0_PORT_ID        PORTB_ID
#define OC0_PIN_ID         PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
void PWM_Timer0_Start(uint8 duty_cycle)
• Description:
	➢ The function responsible for trigger the Timer0 with the PWM Mode.
	➢ Setup the PWM mode with Non-Inverting.
	➢ Setup the prescaler with F_CPU/8.
	➢ Setup the compare value based on the required input duty cycle
	➢ Setup the direction for OC0 as output pin through the GPIO driver.
	➢ The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
• Inputs:
	➢ duty_cycle: The required duty cycle percentage of the generated PWM signal. Its value should be from 0 → 100
• Return: None
*/
void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* PWM_H_ */
