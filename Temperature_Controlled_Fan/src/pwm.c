 /******************************************************************************
 *
 * Module: PWM_TIMER0
 *
 * File Name: pwm.c
 *
 * Description: Source file for the AVR PWM_TIMER0 driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/

#include "pwm.h"

/*******************************************************************************
 *                           Functions Definitions                             *
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
void PWM_Timer0_Start(uint8 duty_cycle)
{

	TCNT0 = 0;     /* Set Timer Initial value to ZERO */

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. Clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

	OCR0  = (duty_cycle/100.0) * 255;      /* Set Compare Value (Duty Cycle here is Percentage) */

	GPIO_setupPinDirection(OC0_PORT_ID, OC0_PIN_ID, PIN_OUTPUT); /* Set PB3/OC0 as Output pin --> pin where the PWM signal is generated from MC. */

}
