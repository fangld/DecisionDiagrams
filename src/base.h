#ifndef BASE_H
#define BASE_H

#include <stdbool.h>

typedef unsigned int uint;

//Constants
#define prime1 741457
#define prime2 4256249
#define prime3 12582917
#define prime4 15485863
#define prime5 1618033999

//Methods
// Swap the values of two integers x and y
inline void swap(uint x, uint y)
{
    x ^= y;
    y ^= x; 
    x ^= y;
}

// Get the actual location of x;
inline uint loc(uint x)
{
    return (x & 0x7FFFFFFF) ;
}

// Decide whether the location of x is complement
inline bool is_comp(uint x)
{
    return (x & 0x80000000) != 0;
}

// A pair function
inline uint pair(uint x, uint y)
{
    return (((x + y) * (x + y + 1)) >> 1) + x;
}


#endif