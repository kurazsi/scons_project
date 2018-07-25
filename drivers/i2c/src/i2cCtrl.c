#include <halTypes.h>

#include <i2cCtrlApi.h>
#include "i2cCtrlPriv.h"


int i2cPortIinit(uint32_t portNr)
{
  if (portNr>=(sizeof(i2cPort)/4)) {
    printf("ERROR i2cPort number is not correct %lu\n", portNr);
    return -1;
  }
  i2cPort[portNr] = 0;
  printf("2cPortIinit\n");
  return 0;
}

int i2cPortWrite(uint32_t portNr, uint32_t data)
{
  if (portNr>=(sizeof(i2cPort)/4)) {
    printf("ERROR i2cPort number is not correct %lu\n", portNr);
    return -1;
  }
  printf("i2cPortWrite\n");
  i2cPort[portNr] = data;
  return 0;
}

uint32_t i2cPortRead(uint32_t portNr)
{
  if (portNr>=(sizeof(i2cPort)/4)) {
    printf("ERROR i2cPort number is not correct %lu\n", portNr);
    return -1;
  }
  printf("i2cPortRead\n");
  return i2cPort[portNr];
}
