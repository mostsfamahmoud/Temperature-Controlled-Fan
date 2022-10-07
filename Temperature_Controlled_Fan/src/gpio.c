/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Mostafa Mahmoud
 *
 * Group: 71
 *
 *******************************************************************************/

#include "gpio.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 portNum, uint8 pinNum, GPIO_PinDirectionType direction)
{

	if ((pinNum >= NUM_OF_PINS_PER_PORT) || (portNum >= NUM_OF_PORTS))
	{
		/* Do Nothing */
		return;
	}

	if (direction == PIN_OUTPUT)
	{
		switch (portNum)
		{
		case PORTA_ID:
			SET_BIT(DDRA, pinNum);
			break;
		case PORTB_ID:
			SET_BIT(DDRB, pinNum);
			break;
		case PORTC_ID:
			SET_BIT(DDRC, pinNum);
			break;
		case PORTD_ID:
			SET_BIT(DDRD, pinNum);
			break;
		}
	}
	else if (direction == PIN_INPUT)
	{
		switch (portNum)
		{
		case PORTA_ID:
			CLEAR_BIT(DDRA, pinNum);
			break;
		case PORTB_ID:
			CLEAR_BIT(DDRB, pinNum);
			break;
		case PORTC_ID:
			CLEAR_BIT(DDRC, pinNum);
			break;
		case PORTD_ID:
			CLEAR_BIT(DDRD, pinNum);
			break;
		}
	}
	else
		return;
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			WRITE_BIT(PORTA, pin_num, value);
			break;
		case PORTB_ID:
			WRITE_BIT(PORTB, pin_num, value);
			break;
		case PORTC_ID:
			WRITE_BIT(PORTC, pin_num, value);
			break;
		case PORTD_ID:
			WRITE_BIT(PORTD, pin_num, value);
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pinValue;
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		pinValue = LOGIC_LOW;
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			pinValue = GET_BIT(PINA, pin_num);
			break;
		case PORTB_ID:
			pinValue = GET_BIT(PINB, pin_num);
			break;
		case PORTC_ID:
			pinValue = GET_BIT(PINC, pin_num);
			break;
		case PORTD_ID:
			pinValue = GET_BIT(PIND, pin_num);
			break;
		}
	}

	return pinValue;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if (port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch (port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if (port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write value on a specific port as required */
		switch (port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 portValue;
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if (port_num >= NUM_OF_PORTS)
	{
		portValue = LOGIC_LOW;
	}
	else
	{
		/* Read and return value on a specific port as required */
		switch (port_num)
		{
		case PORTA_ID:
			portValue =  PINA;
			break;
		case PORTB_ID:
			portValue =  PINB;
			break;
		case PORTC_ID:
			portValue =  PINC;
			break;
		case PORTD_ID:
			portValue =  PIND;
			break;
		}
	}

	return portValue;
}


