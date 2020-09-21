/*
 * main.c
 *
 *  Created on: Jul 7, 2020
 *      Author: mdmad
 */


#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

#include "Spi_int.h"

int main(void)
{
	/* Initialize Micro as Master */
	Spi_vidMasterInit();

	while(1)
	{
		/* Send 'a' on bus */
		(void) Spi_u8MasterTransfer('a');
		/* delay for 1s */
		_delay_ms(1000);

		/* Send 's' on bus */
		(void) Spi_u8MasterTransfer('s');
		/* delay for 1s */
		_delay_ms(1000);

	}


	return 0;
}
