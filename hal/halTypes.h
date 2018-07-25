
#ifndef _HAL_TYPES_H_
#define _HAL_TYPES_H_

// 1: Defines
// ----------------------------------------------------------------------------

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (1)
#endif

#ifndef NULL
#define NULL (0)
#endif

#define ALL_ZEROS (0x00000000)
#define ALL_ONES (0xFFFFFFFF)

/* Limits of integral types.  */


// 2: Typedefs (types, enums, structs)
// ----------------------------------------------------------------------------

// mv typedefs
#include <stdint.h>

// Define for unused variables
#define UNUSED(x) (void)x

typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;

#ifdef __PC__
#include <half.h>
#endif

#if defined(__cpu1__) || defined(__cpu2__) || defined(__cpu3__)
typedef int16_t half;
#endif
typedef half fp16;

typedef float fp32;

typedef union
{
    uint32_t u32;
    float f32;
}u32f32;

// 3: Local const declarations     NB: ONLY const declarations go here
// ----------------------------------------------------------------------------

#endif /* _HAL_TYPES_H_ */
