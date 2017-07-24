#include <stdlib.h>
#include "unitable.h"

void init_unitable(unitable *table, uint slots_size)
{
    slots_size = slots_size < MIN_SLOT_SIZE ? MIN_SLOT_SIZE : slots_size;
    table->slots_size = slots_size;
    table->slots_count = 2;
    table->nodes_count = slots_size;
    table->slots = calloc(MAX_SLOTS_COUNT, sizeof(decnode*));
    table->slots[0] = malloc(slots_size * sizeof(decnode));
    table->slots[1] = calloc(slots_size, sizeof(decnode));
}

void clear_unitable(unitable *table)
{
    if (table->slots == NULL)
    {
        return;
    }

    for (int i = table->slots_count - 1; i >= 0; i--)
    {
        free(table->slots[i]);
        //allocator->slots[i] = NULL;
    }

    free(table->slots);
    table->slots = NULL;
}

void expand_unitable(unitable *table)
{

}

decnode* get_decnode(uint loc)
{

}

uint find_or_add_unitable(unitable *table, uint var_index, uint low, uint high)
{
    return 0;
}