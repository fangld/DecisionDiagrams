#ifndef BASE_H
#define BASE_H

#include <stdbool.h>

typedef unsigned int uint;
typedef unsigned int addr_t;

//Constants
#define prime1 741457
#define prime2 4256249
#define prime3 12582917
#define prime4 15485863
#define prime5 1618033999
#define MAX_NUM_VAR 65535

//Methods
// Swap the values of two integers x and y
inline void swap(uint x, uint y)
{
    x ^= y;
    y ^= x; 
    x ^= y;
}

// Get the actual location of x;
inline addr_t loc(addr_t x)
{
    return (x & 0x7FFFFFFF) ;
}

// Decide whether the location of x is complement
inline bool is_comp(addr_t x)
{
    return (x & 0x80000000) != 0;
}

// A pair function
inline addr_t pair(addr_t x, addr_t y)
{
    return (((x + y) * (x + y + 1)) >> 1) + x;
}


#endif