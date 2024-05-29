#ifndef _CORE_
#define _CORE_

#include "mmap.h"

typedef struct
{
    uint32_t MEMRMP;      // System momory remap register
    uint32_t PMC;         // Peripheral mode configuration register
    uint32_t EXT1CR1;     // External interrupt configuration register 1 (x = 0 to 3)
    uint32_t EXT1CR2;     // External interrupt configuration register 2 (x = 4 to 7)
    uint32_t EXT1CR3;     // External interrupt configuration register 3 (x = 8 to 11)
    uint32_t EXT1CR4;     // External interrupt configuration register 4 (x = 12 to 15)
    uint32_t reserved[2]; // reserved
    uint32_t CMPCR;       // Compensation cell control register
} SYSCFG_TYPE;

#define SYSCFG ((SYSCFG_TYPE *)SYSCFG_BASE)

#endif