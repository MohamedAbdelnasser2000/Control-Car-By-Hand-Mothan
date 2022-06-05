#include "main.h"
int main()
{
	ADC_Initialize();// to Initialize Analog to Digital convartor
	LCD_Initialize();
	UART_Initialize(Asynchronous,Disable,Bit_1,Bits_8);// to Initialize UART Communication protocol
	int volt_on_pot1; // to Received the value of POT1 IN it
	int volt_on_pot2; // to Received the value of POT2 IN it
	int volt_on_pot3; // to Received the value of POT3 IN it
	while(1)
	{
		volt_on_pot1=ADC_Read(ADC0);
		_delay_ms(1000);
		LCD_Write_Number(volt_on_pot1);
		LCD_Write_String((uint8_t*)"pot1");
		_delay_ms(1000);
		LCD_Clear();
		if (volt_on_pot1>=400 && volt_on_pot1<=800)
		{
			LCD_Write_String((uint8_t*)"forward");
			_delay_ms(1000);
			LCD_Clear();
			UART_Transmit(1);
			// 1  is forward
		}
		else if(volt_on_pot1>800 && volt_on_pot1<=2000)
		{
			LCD_Write_String((uint8_t*)"back");
			_delay_ms(1000);
			LCD_Clear();
			UART_Transmit(2);
			// 2 is back
		}
		else
		{
			volt_on_pot3=ADC_Read(ADC2);
			_delay_ms(1000);
			LCD_Write_Number(volt_on_pot3);
			LCD_Write_String((uint8_t*)"pot2");
			_delay_ms(1000);
			LCD_Clear();
			if (volt_on_pot3>=400 && volt_on_pot3<=500)
			{
				LCD_Write_String((uint8_t*)"Rigth");
				_delay_ms(1000);
				LCD_Clear();
				UART_Transmit(3);
				// 3  is Rigth
			}
			else if(volt_on_pot3>500 && volt_on_pot3<=2000)
			{
				LCD_Write_String((uint8_t*)"Left");
				_delay_ms(1000);
				LCD_Clear();
				UART_Transmit(4);
				// 2 is Left
			}
			else
			LCD_Write_String((uint8_t*)"Direction Error");
		}
	}
	
	return 0;
}