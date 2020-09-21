/*
 * Spi_prog.c
 *
 *  Created on: Jul 7, 2020
 *      Author: mdmad
 */

#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"

#include "Dio_int.h"

#include "Spi_int.h"
#include "Spi_priv.h"

void Spi_vidMasterInit(void)
{
	/************************************************
	 * 					Master   |  Slave			*
	 * 				------------------------		*
	 *PB4  12->SS      O/P         I/P  (Pull-Up)	*
	 *PB4  13->MOSI    O/P	   	   I/P				*
	 *PB4  14->MISO	   I/P		   O/P				*
	 *PB4  15->SCK 	   O/P		   I/P				*
	 ************************************************/
	Dio_vidSetPinDir(DIO_u8PIN_12,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_13,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_14,DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_15,DIO_u8OUTPUT);

	/* Enable Spi */

	SET_BIT(SPCR,6);

	/* select MSB first data order */
	CLR_BIT(SPCR,5);

	/* Select Master Role */
	SET_BIT(SPCR,4);

	/* Select Falling edge as leading edge " High Idle State" */
	SET_BIT(SPCR,3); //CPOL

	/* SELECT Set UP First */
	SET_BIT(SPCR,2);  //CPHA

	/* Select Fosc/64 for SCK  wde msh hn7otha f el slave l2n msh mntky n de tkon hnak msh lazm ykon 3rfha */
	SET_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	CLR_BIT(SPSR,0);  //SPI2X

}


void Spi_vidSlaveInit(void)
{

	/************************************************
	 * 					Master   |  Slave			*
	 * 				------------------------		*
	 *PB4  12->SS      O/P         I/P  (Pull-Up)	*
	 *PB4  13->MOSI    O/P	   	   I/P				*
	 *PB4  14->MISO	   I/P		   O/P				*
	 *PB4  15->SCK 	   O/P		   I/P				*
	 ************************************************/
	Dio_vidSetPinDir(DIO_u8PIN_12,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8HIGH);  /* Pull - Up */
	Dio_vidSetPinDir(DIO_u8PIN_13,DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_14,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_15,DIO_u8INPUT);

	/* Enable Spi */

	SET_BIT(SPCR,6);

	/* select MSB first data order */
	CLR_BIT(SPCR,5);

	/* Select Slave Role */
	CLR_BIT(SPCR,4);

	/* Select Falling edge as leading edge " High Idle State" */
	SET_BIT(SPCR,3); //CPOL

	/* SELECT Set UP First */
	SET_BIT(SPCR,2);  //CPHA


}
u8 Spi_u8MasterTransfer(u8 Data)
{
	/* select slave  */
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8LOW);


	/* load the register with the data to be transfer */
	SPDR = Data;

	/* wait till the transferring complete */
	while(GET_BIT(SPSR,7) == 0);

	/* release the slave */
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8HIGH);

	/* return the received data */
	return SPDR;


}

u8 Spi_u8SlaveTransfer(u8 Data)
{
	/* load the register with the data to be transfer */
	SPDR = Data;

	/* wait till the transferring complete */
	while(GET_BIT(SPSR,7) == 0);

	/* return the received data */
	return SPDR;


}
