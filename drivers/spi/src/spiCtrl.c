#include <halTypes.h>

#include <spiCtrlApi.h>
#include "spiCtrlPriv.h"


int spiPortIinit(uint32_t portNr)
{
  if (portNr>=(sizeof(spiPort)/4)) {
    printf("ERROR spiPort number is not correct %lu\n", portNr);
    return -1;
  }
  spiPort[portNr] = 0;
  printf("2cPortIinit\n");
  return 0;
}

int spiPortWrite(uint32_t portNr, uint32_t data)
{
  if (portNr>=(sizeof(spiPort)/4)) {
    printf("ERROR spiPort number is not correct %lu\n", portNr);
    return -1;
  }
  printf("spiPortWrite\n");
  spiPort[portNr] = data;
  return 0;
}

uint32_t spiPortRead(uint32_t portNr)
{
  if (portNr>=(sizeof(spiPort)/4)) {
    printf("ERROR spiPort number is not correct %lu\n", portNr);
    return -1;
  }
  printf("spiPortRead\n");
  return spiPort[portNr];
}
