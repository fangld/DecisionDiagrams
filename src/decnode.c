#include "decnode.h"
#include <stdlib.h>

void init_allocator(decnodes_allocator *allocator, size_t slotsSize)
{
    allocator->slots_size = slotsSize < MIN_SLOT_SIZE ? MIN_SLOT_SIZE : slotsSize;
    allocator->slots = calloc(MAX_SLOTS_COUNT, sizeof(decnode*));
    allocator->slots[0] = calloc(slotsSize, sizeof(decnode));
    allocator->slots_count = 1;
    allocator->nodes_count = 65536;
}

void clear_allocator(decnodes_allocator *allocator)
{
    if (allocator->slots == NULL)
    {
        return;
    }

    for (int i = allocator->slots_count - 1; i >= 0; i--)
    {
        free(allocator->slots[i]);
        //allocator->slots[i] = NULL;
    }

    free(allocator->slots);
    allocator->slots = NULL;
}

uint get_free_decnode(decnodes_allocator *allocator)
{
    if (allocator->nodes_count == allocator->slots_count * allocator->slots_size)
    {
        allocator->slots[allocator->slots_count] = calloc(allocator->slots_size, sizeof(decnode));
        allocator->slots_count++;
    }
    //allocator->nodesCount++;
    //nodesCount++;
    return ++allocator->nodes_count;
}