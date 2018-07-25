#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_

// 1: Includes
// ----------------------------------------------------------------------------

#include <halTypes.h>

#ifdef __cplusplus
extern "C" {
#endif


// 2: Specific #defines and types  (typedef,enum,struct)
// ----------------------------------------------------------------------------

#define DEFAULT_APP_CLOCK_KHZ       100000
#define DEFAULT_OSC_CLOCK_KHZ       14000

// 3: Exported Global Data (generally better to avoid)
// ----------------------------------------------------------------------------

// 4: Exported Functions (non-inline)
// ----------------------------------------------------------------------------

// initializes clocks and memory configurations (including caches) for the current application
int initClocksAndMemory( void );


#ifdef __cplusplus
}
#endif


#endif // _APP_CONFIG_H_
