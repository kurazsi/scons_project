
#ifndef SPI_PORT_H
#define SPI_PORT_H 

const uint32_t MaxSpiPortNR = 10;

int spiPortIinit(uint32_t portNr);

uint32_t spiPortWrite(uint32_t portNr, uint32_t data);

uint32_t spiPortRead(uint32_t portNr);

#endif //SPI_PORT_H