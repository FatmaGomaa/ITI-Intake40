/*
 * dSPI_Private.h
 *
 *  Created on: Apr 22, 2020
 *      Author: FatmaGomaa
 */

#ifndef MCAL_SPI_DSPI_PRIVATE_H_
#define MCAL_SPI_DSPI_PRIVATE_H_

#define SPI_ONE_BASE                                    SPI_1_BASE_ADDRESS
#define SPI_TWO_BASE                                    SPI_2_BASE_ADDRESS
#define SPI_THREE_BASE                                  SPI_3_BASE_ADDRESS

#define SPI_1_BASE_ADDRESS							((volatile void * const)(0x40013000))
#define SPI_2_BASE_ADDRESS							((volatile void * const)(0x40003800))
#define SPI_3_BASE_ADDRESS                          ((volatile void * const)(0x40013C00))


#endif /* MCAL_SPI_DSPI_PRIVATE_H_ */
