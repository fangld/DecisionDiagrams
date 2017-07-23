#ifndef DECNODE_H
#define DECNODE_H

#include <stdlib.h>

//Constants
#define MAX_SLOTS_COUNT 65536
#define MIN_SLOT_SIZE 131072

//Data structures
typedef struct decnode {
    uint var_index;
    uint low;
    uint high;
    uint next;
    uint ref_count;
} decnode;

typedef struct decnodes_allocator {
    int slots_count;
    int slots_size;
    int nodes_count;
    decnode **slots;
} decnodes_allocator;

//Methods
void init_allocator(decnodes_allocator *allocator, size_t slotsSize);
void clear_allocator(decnodes_allocator *allocator);
uint get_free_decnode(decnodes_allocator *allocator);

#endif