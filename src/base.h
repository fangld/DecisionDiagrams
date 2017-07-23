#ifndef DECNODE_H
#define DECNODE_H

#include <stdlib.h>

//Constants
#define prime1 741457
#define prime2 4256249
#define prime3 12582917
#define prime4 15485863
#define prime5 1618033999

//Data structures


//Methods
#define swap(x, y) {x ^= y; y ^= x; x ^= y;}
#define loc(x)     ((x) & 07FFFFFFF)
#define is_comp(x) ((x) & 0x80000000)
#define pair(x, y) ((((x) + (y)) * ((x) + (y) + 1) >> 1) + (x))

// inline void swap(uint x, uint y)
// {
//     x ^= y;
//     y ^= x;
//     x ^= y;
// }

#endif