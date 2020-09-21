/*
 * Spi_priv.h
 *
 *  Created on: Jul 7, 2020
 *      Author: mdmad
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_



#define SPDR (*(volatile u8*) 0x2F)
#define SPSR (*(volatile u8*) 0x2E)
#define SPCR (*(volatile u8*) 0x2D)


#endif /* SPI_PRIV_H_ */
