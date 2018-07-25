
#ifndef I2C_PORT_H
#define I2C_PORT_H 

const uint32_t MaxI2cPortNR = 10;

int i2cPortIinit(uint32_t portNr);

uint32_t i2cPortWrite(uint32_t portNr, uint32_t data);

uint32_t i2cPortRead(uint32_t portNr);

#endif //I2C_PORT_H