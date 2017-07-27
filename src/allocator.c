#include <stdlib.h>
#include "allocator.h"

decnodes_allocator* create_allocator(size_t num_node_slot)
{
    decnodes_allocator* result = malloc(sizeof(decnodes_allocator));
    result->nodes_count = INIT_NUM_NODES;
    if (num_node_slot < MIN_NUM_NODE_SLOT)
    {
        result->num_nodes_slot = MIN_NUM_NODE_SLOT;
        result->slots_size = MIN_NUM_NODE_SLOT * sizeof(decnode);
        result->cur_slot_index = 1;
        result->slots_count = 2;
        result->slots = malloc(MAX_SLOTS_COUNT * sizeof(decnode*));
    
        //Allocate the memory for the first two slots    
        result->slots[0] = malloc(result->slots_size);
        result->slots[1] = malloc(result->slots_size);
    }
    else
    {
        result->num_nodes_slot = num_node_slot;
        result->slots_size = num_node_slot * sizeof(decnode);
        result->cur_slot_index = 0;
        result->slots_count = 1;
        result->slots = malloc(MAX_SLOTS_COUNT * sizeof(decnode*));
    
        //Allocate the memory for the first slot 
        result->slots[0] = malloc(result->slots_size);
        //result->cur_slot = result->slots[0];
    }

    result->cur_slot = result->slots[result->cur_slot_index];
    return result;
}

decnode* allocate_node(decnodes_allocator *allocator)
{
    decnode* result;
    if (allocator->cur_slot_index != allocator->num_nodes_slot)
    {
        result = allocator->cur_slot + allocator->cur_slot_index;
        allocator->cur_slot_index++;
    }
    else
    {
        allocator->cur_slot++;
        allocator->cur_slot = malloc(allocator->slots_size);
        result = allocator->cur_slot;
        allocator->cur_slot_index = 1;
        allocator->slots_count++;
    }
    allocator->nodes_count++;
    return result;
}

void gc_allocator(decnodes_allocator *allocator)
{
    
}

void clear_allocator(decnodes_allocator *allocator)
{
    if (allocator->slots != NULL)
    {
        decnode** slots = allocator->slots;
        for (int i = allocator->slots_count - 1; i >= 0; i--)
        {
            free(slots[i]);
        }

        free(slots);
        allocator->slots = NULL;
    }    
}