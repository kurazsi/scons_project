
#ifndef REG_UTILS_H
#define REG_UTILS_H 

#include "halTypes.h"

// ----------------------------------------------------------------------------
// 1: Includes
// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

// 2:  Exported Global Data (generally better to avoid)
// ----------------------------------------------------------------------------

// 3:  Exported Functions (non-inline)
// ----------------------------------------------------------------------------

void HalRegSetBitField(void * regAddress, u32 startBit, u32 numBits, u32 value);

/// Returns the value of a particular bitfield
u32 HalRegGetBitField(void * regAddress, u32 startBit, u32 numBits);

/// Perform a bit manipulation on register based on mask value
void HalRegBitOperation(void * regAddress, tyRegMaskOperation operation, u32 value);

#ifdef __cplusplus
}
#endif

#endif // REG_UTILS_H  
