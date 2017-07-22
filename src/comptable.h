#ifndef UNITABLE_H
#define UNITABLE_H

#include "decnode.h"

//Data structures
typedef struct comptable {
    int *items;
    int shift_size;
    int count;
} comptable;

//Methods
void init_comptable(comptable *table);
void clear_comptable(comptable *table);
void expand_comptable(comptable *table);
int find_or_add_comptable(comptable *table, int var_index, int low, int high);

#endif