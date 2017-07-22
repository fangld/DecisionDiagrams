#ifndef DECNODE_H
#define DECNODE_H

#include <stdlib.h>

//Constants
#define MAX_SLOTS_COUNT 65536
#define MIN_SLOT_SIZE 131072

//Data structures
typedef struct decnode {
    int var_index;
    int low;
    int high;
    int next;
} decnode;

typedef struct decnodes_allocator {
    int slotsCount;
    int slotsSize;
    int nodesCount;
    decnode **slots;
} decnodes_allocator;

//Methods
void init_allocator(decnodes_allocator *allocator, size_t slotsSize);
void clear_allocator(decnodes_allocator *allocator);
int get_free_decode(decnodes_allocator *allocator);

#endif