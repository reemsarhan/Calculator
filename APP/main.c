#include "../HAL/LCD/LCD.h"
#include "../HAL/KeyPad/KeyPad.h"
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/Definitions.h"

int main()
{
    HLCD_void8bitInit();
    HKPD_voidInit(PORTC);  // Keypad

    u8 PressedKey = ' ';
    s32 operand1 = 0;
    s32 operand2 = 0;
    u8  operator = ' ';
    s32 result = 0;
    u8 f = 0;

    while (1)
    {
    	PressedKey = HKPD_u8GetKeyPressed();

        if (PressedKey != ' ')
        {
            if (PressedKey >= '0' && PressedKey <= '9')
            {
                if (operator == ' ' && !f)
                {
                	operand1 = (operand1 * 10) + (PressedKey - '0');
                    HLCD_voidClear();
                    HLCD_voidSetCursor(1, 1);
                    HLCD_voidDisplayNum(operand1);
                }
                else
                {
                	operand2 = (operand2 * 10) + (PressedKey - '0');
                    HLCD_voidClear();
                    HLCD_voidSetCursor(1, 1);
                    HLCD_voidDisplayNum(operand1);
                    HLCD_voidSetCursor(1, 7);
                    HLCD_voidDisplayChar(operator);
                    HLCD_voidSetCursor(1, 9);
                    HLCD_voidDisplayNum(operand2);
                }
            }
            else if (PressedKey == 'c')
            {
            	operand1 = 0;
            	operand2 = 0;
            	operator = ' ';
            	result = 0;
                f = 0;
                HLCD_voidClear();
            }
            else if (PressedKey == '+' || PressedKey == '-' || PressedKey == '*' || PressedKey == '/')
            {
            	operator = PressedKey;
                HLCD_voidClear();
                HLCD_voidSetCursor(1, 1);
                HLCD_voidDisplayNum(operand1);
                HLCD_voidSetCursor(1, 7);
                HLCD_voidDisplayChar(operator);
            }
            else if (PressedKey == '=')
            {
                switch (operator)
                {
                    case '+':
                    	result = operand1 + operand2;
                        break;
                    case '-':
                    	result = operand1 - operand2;
                        break;
                    case '*':
                    	result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 != 0)
                        {
                        	result = operand1 / operand2;
                        }
                        break;
                }
                HLCD_voidClear();
                HLCD_voidSetCursor(1, 1);
                HLCD_voidDisplayNum(operand1);
                HLCD_voidSetCursor(1, 5);
                HLCD_voidDisplayChar(operator);
                HLCD_voidSetCursor(1, 9);
                HLCD_voidDisplayNum(operand2);
                HLCD_voidSetCursor(2, 1);
                HLCD_voidDisplayChar('=');
                HLCD_voidSetCursor(2, 3);
                HLCD_voidDisplayNum(result);

                operand1 = result;
                operand2 = 0;
                operator = ' ';
                f = 1;
            }
        }
    }

    return 0;
}
