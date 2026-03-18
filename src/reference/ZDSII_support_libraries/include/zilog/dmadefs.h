/*!\file dmadefs.h
 * \brief DMA register bit definitions for Z8 Encore! UART Devices.
 *  
 *  This file contains header information required by DMA driver
 *  implementations for Z8 Encore! microcontrollers.
 *
 *  This source file uses Doxygen-style comments to generate
 *  documentation automatically.
 *
 *  Copyright (C) 1999-2004 by  ZiLOG, Inc.
 *  All Rights Reserved.
 */

#pragma once // Include this file only once
#ifndef _DMADEFS_H_
#define _DMADEFS_H_


#include <defines.h>

#define IRQ_DMA				((BYTE)0x10)	//!< DMA interrupt enable.

#define DMA_CTL_DEN		((BYTE)0x80)	//!< Enable DMA.
#define DMA_CTL_DLE			((BYTE)0x40)	//!< DMA loop enable.
#define DMA_CTL_DDIR		((BYTE)0x20)	//!< DMA data transfer direction.
#define DMA_CTL_IRQEN		((BYTE)0x10)	//!< DMA interrupt request enable.
#define DMA_CTL_WSEL		((BYTE)0x08)	//!< Word select.
#define DMA_CTL_RSS_TMR0	((BYTE)0x00)	//!< Request trigger source select for Timer0.
#define DMA_CTL_RSS_TMR1	((BYTE)0x01)	//!< Request trigger source select for Timer1.
#define DMA_CTL_RSS_TMR2	((BYTE)0x02)	//!< Request trigger source select for Timer2.
#define DMA_CTL_RSS_TMR3	((BYTE)0x03)	//!< Request trigger source select for Timer3.
#define DMA_CTL_RSS_UART0	((BYTE)0x04)	//!< Request trigger source select for UART0 Rx/Tx.
#define DMA_CTL_RSS_UART1 	((BYTE)0x05)	//!< Request trigger source select for UART1 Rx/Tx.
#define DMA_CTL_RSS_I2C	((BYTE)0x06)	//!< Request trigger source select for I2C Rx/Tx.

#define DMAA_STAT_CADC	((BYTE)0xF0)	//!< Current ADC analog input.
#define DMAA_STAT_IRQA		((BYTE)0x04)	//!< DMA_ADC interrupt request indicator.
#define DMAA_STAT_IRQ1		((BYTE)0x02)	//!< DMA1 interrupt request indicator.
#define DMAA_STAT_IRQ0		((BYTE)0x01)	//!< DMA0 interrupt request indicator.


#endif /*! _DMADEFS_H_ */


/*! End of File */


