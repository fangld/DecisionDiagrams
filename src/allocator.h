#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>
#include "base.h"
#include "decnode.h"

#define MAX_SLOTS_COUNT 65536
#define INIT_NUM_NODES 65536
#define MIN_NUM_NODE_SLOT 131072

//Data structure
typedef struct decnodes_allocator {
    size_t num_nodes_slot;
    size_t cur_slots_off;
    size_t slots_size;
    size_t slots_count;
    size_t nodes_count;
    decnode *cur_slot;
    decnode **slots;
} decnodes_allocator;

//Methods
decnodes_allocator* create_allocator(size_t num_node_slot);
void clear_allocator(decnodes_allocator *allocator);
decnode* allocate_node(decnodes_allocator *allocator);
void gc_allocator(decnodes_allocator *allocator);

#endif