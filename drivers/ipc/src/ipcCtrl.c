#include <halTypes.h>
#include <halRegUtils.h>
#include <halWhoAmI.h>

#include <ipcCtrlApi.h>
#include "ipcCtrlPriv.h"


int ipcWrite(halProcessorType procID, uint32_t data)
{

  if (procID>=(sizeof(ipcBuffer)/4)) {
    printf("ERROR ipc procID number is not correct %lu\n", procID);
    return -1;
  }

  uint32_t * reg = ipcBuffer[procID];
  halProcessorType cpuId = HalWhoAmI();
  if (cpuId == PROCESS_CPU1)
  {
    reg = (uint32_t *)CPU1_IP_REG_ADDR;
  } else if (cpuId == PROCESS_CPU2)
  {
    reg = (uint32_t *)CPU2_IP_REG_ADDR;
  } else if (cpuId == PROCESS_CPU3)
  {
    reg = (uint32_t *)CPU3_IP_REG_ADDR;
  } else
  {
    reg = (uint32_t *)CPU4_IP_REG_ADDR;
  }

  *(*reg) = data;

  return 0;
}

uint32_t ipcRead( void )
{
  halProcessorType cpuId = HalWhoAmI();
  
  uint32_t ** reg = &ipcBuffer[cpuId];
  
  if (cpuId == PROCESS_CPU1)
  {
    *reg = (uint32_t *)CPU1_IP_REG_ADDR;
  } else if (cpuId == PROCESS_CPU2)
  {
    *reg = (uint32_t *)CPU2_IP_REG_ADDR;
  } else if (cpuId == PROCESS_CPU3)
  {
    *reg = (uint32_t *)CPU3_IP_REG_ADDR;
  } else
  {
    *reg = (uint32_t *)CPU4_IP_REG_ADDR;
  }

  return  *(*reg);
}
