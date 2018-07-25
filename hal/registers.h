// This file just allows us to have a common header for different architectures

#ifndef REGISTERS_H
#define REGISTERS_H

#ifndef __PC__
const u32 CPU1_IP_REG_ADDR=0x70000000;
const u32 CPU2_IP_REG_ADDR=0x70001000;
const u32 CPU3_IP_REG_ADDR=0x70002000;
const u32 CPU4_IP_REG_ADDR=0x70003000;
#else
volatile u32 CPU1_IP_REG=0;
volatile u32 CPU2_IP_REG=0;
volatile u32 CPU3_IP_REG=0;
volatile u32 CPU4_IP_REG=0;

const u32 CPU1_IP_REG_ADDR=(u32)&CPU1_IP_REG;
const u32 CPU2_IP_REG_ADDR=(u32)&CPU2_IP_REG;
const u32 CPU3_IP_REG_ADDR=(u32)&CPU3_IP_REG;
const u32 CPU4_IP_REG_ADDR=(u32)&CPU4_IP_REG;
#endif

#endif
