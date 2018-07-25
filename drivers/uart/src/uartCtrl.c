#include <halTypes.h>

#include <uartCtrlApi.h>
#include "uartCtrlPriv.h"


int uartPortIinit(uint32_t portNr)
{
  if (portNr>=(sizeof(uartPort)/4)) {
    printf("ERROR uartPort number is not correct %lu\n", portNr);
    return -1;
  }
  uartPort[portNr] = 0;
  printf("2cPortIinit\n");
  return 0;
}

int uartPortWrite(uint32_t portNr, uint32_t data)
{
  if (portNr>=(sizeof(uartPort)/4)) {
    printf("ERROR uartPort number is not correct %lu\n", portNr);
    return -1;
  }
  printf("uartPortWrite\n");
  uartPort[portNr] = data;
  return 0;
}

uint32_t uartPortRead(uint32_t portNr)
{
  if (portNr>=(sizeof(uartPort)/4)) {
    printf("ERROR uartPort number is not correct %lu\n", portNr);
    return -1;
  }
  printf("uartPortRead\n");
  return uartPort[portNr];
}
