#ifndef HAL_WHOAMI_H_
#define HAL_WHOAMI_H_

#include <registers.h>

#ifndef CFG_NUM_CPUS
#error ERROR: CFG_NUM_CPUS not defined in file (__FILE__)
#endif

typedef enum {
    PROCESS_DEBUGGER = 0,
    PROCESS_CPU1,
    PROCESS_CPU2,
    PROCESS_CPU3,
    #if CFG_NUM_CPUS > 3
        PROCESS_CPU4,
        PROCESS_CPU5,
        PROCESS_CPU6,
    #endif
    NUMBER_OF_PROCESSES,
    ERROR_ID,
} halProcessorType;

#if defined(__cpu1__)
    #define CPU1_CORE
#elif  defined(__cpu2__)
    #define CPU2_CORE
#elif  defined(__cpu3__)
    #define CPU3_CORE
#else
    #define OTHER_CORE
#endif

__attribute__((no_instrument_function)) 
static inline halProcessorType HalWhoAmI();

static inline halProcessorType HalWhoAmI()
{
    #ifdef CPU1_CORE
        // We are one of the cpu1 processors
        return PROCESS_CPU1;
    #endif
    #ifdef CPU2_CORE
        return PROCESS_CPU2;
    #endif   
    #ifdef CPU3_CORE
        return PROCESS_CPU3;
    #endif    
    #ifdef OTHER_CORE
        #if CFG_NUM_CPUS > 3
        int Number;
        Number = __builtin_getcpuid();
        switch(Number){
          case 0: return PROCESS_CPU4;
          case 1: return PROCESS_CPU5;
          case 2: return PROCESS_CPU6;
          default:
            break;
        }
        #endif
    #endif
        return ERROR_ID;
}

static inline const char * HalGetProcessorName(int process)
{
    switch(process)
    {
        case PROCESS_CPU1: return "CPU1";
        case PROCESS_CPU2: return "CPU2";
        case PROCESS_CPU3: return "CPU3";
    #if CFG_NUM_CPUS > 3
        case PROCESS_CPU4: return "CPU4";
        case PROCESS_CPU5: return "CPU5";
        case PROCESS_CPU6: return "CPU6";
    #endif
        default:
            break;
    }
    return "UNK";
}

#endif
