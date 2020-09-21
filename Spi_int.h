/*
 * Spi_int.h
 *
 *  Created on: Jul 7, 2020
 *      Author: mdmad
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_
/* de data ay 7aga bb3tha ll slave lw na 3ayz a2ra elly gwah w
 * el slave msh care 5als b el data de  */
#define SPI_u8DUMMY_DATA  0xFF

void Spi_vidMasterInit(void);
void Spi_vidSlaveInit(void);

u8 Spi_u8MasterTransfer(u8 Data);
u8 Spi_u8SlaveTransfer(u8 Data);


#endif /* SPI_INT_H_ */
