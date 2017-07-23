#ifndef UNITABLE_H
#define UNITABLE_H

#include "base.h"
#include "decnode.h"

//Data structures
typedef struct unitable {
    uint *items;    
    uint count;
    uint shift_size;
    
} unitable;

//Methods
void init_unitable(unitable *table);
void clear_unitable(unitable *table);
void expand_unitable(unitable *table);
uint find_or_add_unitable(unitable *table, uint var_index, uint low, uint high);

#endif