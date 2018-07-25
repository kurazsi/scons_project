
#ifndef UART_PORT_H
#define UART_PORT_H 

#if defined(__CPU1__)
	#include "uartCfg1.h"
#elif defined(__CPU2__)
	#include "uartCfg2.h"
#elif defined(__CPU2__)
	#include "uartCfg3.h"
#endif

int uartPortIinit(uint32_t portNr);

uint32_t uartPortWrite(uint32_t portNr, uint32_t data);

uint32_t uartPortRead(uint32_t portNr);

#endif //UART_PORT_H