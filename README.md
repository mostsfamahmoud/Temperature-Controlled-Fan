# Temperature-Controlled Fan

## `Aim:`
Design a temperature-controlled fan using ***`ATmega32`*** microcontroller, 
in which the fan is automatically turned ON or OFF according to the 
temperature. 
Use ATmega32 Microcontroller with frequency 1Mhz.


## `Description:`

1. `LM35 temperature` sensor will give continuous analog output            corresponding to the temperature sensed by it. This analog signal is given to the     ADC, which converts the analog values to digital values.

2. The digital output of the `ADC` is equivalent to **sensed analog voltage**.

3. In order to get the temperature from the sensed analog voltage, we need to perform some calculations in the programming for the microcontroller.

4. Once the calculations are done by the microcontroller according to the logic, the 
temperature is displayed on the LCD. 

5. The microcontroller will continuously monitor the temperature and based on the 
temperature value, the microcontroller will drive the fan like that:

| Temperature (C)              | Fan State | Fan Speed (Percentage from Max) |
| :---                         |     :---: |          :---:                  |
| Less than 30                 | OFF       | 0 %                             |
| Greater than or equal 30     | ON        | 25 %                            |
| Greater than or equal 60     | ON        | 50 %                            |
| Greater than or equal 90     | ON        | 75 %                            |
| Greater than or equal 120    | ON        | 100 %                           |

6. The ***main principle*** of the circuit is to **switch on/off** the fan connected to **`DC Motor`** based on temperature value. The DC-Motor rotates in `Clock-Wise` direction or stopped based on the fan state.

8. The LCD should display the temperature value and the fan state continuously like 
that:

![This is an image](Project SnapShots/LCD_Display.png)

9. Control the DC-Motor speed using PWM signal generated from Timer0.
