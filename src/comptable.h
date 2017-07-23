#ifndef COMPTABLE_H
#define COMPTABLE_H

#include "base.h"
#include "decnode.h"

//Data structures
typedef struct comptable {
    uint *items;
    uint shift_size;
    uint count;
} comptable;

//Methods
void init_comptable(comptable *table);
void clear_comptable(comptable *table);
void expand_comptable(comptable *table);
uint find_or_add_comptable(comptable *table, int var_index, int low, int high);

#endif