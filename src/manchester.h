#ifndef MANCHESTER_H
#define MANCHESTER_H

/* Includes */
#include "stdint.h"
#include "stdio.h"

/* Types */
typedef uint8_t Manchester_Bit_t;

/* Constants */
static const Manchester_Bit_t Low   = 0U;
static const Manchester_Bit_t High  = 1U;
static const Manchester_Bit_t Undef = 2U;

/* Prototypes */
Manchester_Bit_t Manchester_Process_Edge( Manchester_Bit_t clock,
                                          Manchester_Bit_t data );

#endif /* MANCHESTER_H */
