#include "decnode.h"
#include <stdlib.h>

void init_allocator(decnodes_allocator *allocator, size_t slotsSize)
{
    allocator->slotsSize = slotsSize < MIN_SLOT_SIZE ? MIN_SLOT_SIZE : slotsSize;
    allocator->slots = calloc(MAX_SLOTS_COUNT, sizeof(decnode*));
    allocator->slots[0] = calloc(slotsSize, sizeof(decnode));
    allocator->slotsCount = 1;
    allocator->nodesCount = 65536;
}

void clear_allocator(decnodes_allocator *allocator)
{
    if (allocator->slots == NULL)
    {
        return;
    }

    for (int i = allocator->slotsCount - 1; i >= 0; i--)
    {
        free(allocator->slots[i]);
        //allocator->slots[i] = NULL;
    }

    free(allocator->slots);
    allocator->slots = NULL;
}

int get_free_decode(decnodes_allocator *allocator)
{
    if (allocator->nodesCount == allocator->slotsCount * allocator->slotsSize)
    {
        allocator->slots[allocator->slotsCount] = calloc(allocator->slotsSize, sizeof(decnode));
        allocator->slotsCount++;
    }
    //allocator->nodesCount++;
    //nodesCount++;
    return ++allocator->nodesCount;
}