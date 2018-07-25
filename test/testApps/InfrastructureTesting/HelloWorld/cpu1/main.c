// 1: Includes
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "app_config.h"


// 2: Source Specific #defines and types  (typedef,enum,struct)
// ----------------------------------------------------------------------------

// 3: Global Data (Only if absolutely necessary)
// ----------------------------------------------------------------------------
extern u32 * cpu2_entryPoint;
extern u32 * cpu3_entryPoint;

// 4: Static Local Data
// ----------------------------------------------------------------------------

// 5: Static Function Prototypes
// ----------------------------------------------------------------------------

// 6: Functions Implementation
// ----------------------------------------------------------------------------

int main( void * args )
{
    UNUSED(args);

    if (!initClocksAndMemory())
    {
        printf("Error initializing clocks and memory\n");
        return -1;
    }

    printf("Hello World from LEON\n");

    

    // exit app
    return 0;
}

