
#ifndef IPC_PRIVATE_H
#define IPC_PRIVATE_H 

#include <halTypes.h>

#ifndef CFG_NUM_CPUS
#error ERROR: CFG_NUM_CPUS not defined in file (__FILE__)
#endif

volatile SHARED_DATA uint32_t * ipcBuffer[CFG_NUM_CPUS] ALIGNED(8);


#endif //IPC_PRIVATE_H