/* 
 * File:   std_types.h
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:12 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/* Includes Section */
#include "compiler.h"
#include "std_libraries.h"

/* Function Like Macros Declarations Section*/


/* Data Types Declarations */
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

typedef uint8              Std_ReturnType;

/* Macros Declarations Section */
#define STD_HIGH      0x01
#define STD_LOW       0x00

#define STD_ON        0x01
#define STD_OFF       0x00

#define STD_ACTIVE    0x01
#define STD_IDLE      0x00

#define E_OK          (Std_ReturnType)0x01
#define E_NOT_OK      (Std_ReturnType)0x00

/* Function Declarations Section */

#endif	/* STD_TYPES_H */

