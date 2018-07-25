// 1: Includes
// ----------------------------------------------------------------------------
#include "halRegUtils.h"


// 2:  Source Specific #defines and types  (typedef,enum,struct)
// ----------------------------------------------------------------------------
#define GEN_BIT_MASK(numBits) ( (numBits) >= 32U ? 0xFFFFFFFF : ((1U << (numBits)) - 1U) )
// 3: Global Data (Only if absolutely necessary)
// ----------------------------------------------------------------------------

// 4: Static Local Data 
// ----------------------------------------------------------------------------

// 5: Static Function Prototypes
// ----------------------------------------------------------------------------

// 6: Functions Implementation
// ----------------------------------------------------------------------------

void HalRegBitMaskOp(void * regAddress, tyRegMaskOperation operation, u32 value)
{
    volatile u32 *reg = ((volatile u32 *)regAddress);
    switch (operation)
    {
    case SET_WORD:
        *reg = (u32)(value);
        break;
    case SET_BITS:
        u32 Val = *reg;
        Val |= value;
        *reg = Val;
        break;
    case CLR_BITS:
        u32 Val = *reg;
        Val &= ~value;
        *reg = Val;
        break; 
    }
    return;
}

void HalRegSetBitField(void * regAddress, u32 startBit, u32 numBits, u32 value)
{
    volatile u32 *reg = ((volatile u32 *)regAddress);
    u32 initialValue;
    u32 mask;
    initialValue = *reg;
    mask = GEN_BIT_MASK(numBits);
    // Ensure that the value isn't larger than the number of bits requested
    value &= mask;
    mask = mask << startBit;
    // Clear the relevant bits in the initial value
    initialValue = initialValue & (~mask);
    // now OR in the new value
    initialValue = initialValue | (value << startBit);
    *reg = initialValue;
    return;
}

u32 HalRegGetBitField(void * regAddress, u32 startBit, u32 numBits)
{
    volatile u32 *reg = ((volatile u32 *)regAddress);
    u32 initialValue;
    u32 mask;
    initialValue = *reg;

    // Shift down to the bits of interest
    initialValue = initialValue >> startBit;
    mask = GEN_BIT_MASK(numBits); // Mask for the bits of interest

    return (initialValue & mask);
}

