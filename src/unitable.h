#ifndef UNITABLE_H
#define UNITABLE_H

#include "decnode.h"

//Data structures
typedef struct unitable {
    int *items;
    int shift_size;
    int count;
} unitable;

//Methods
void init_unitable(unitable *table);
void clear_unitable(unitable *table);
void expand_unitable(unitable *table);
int find_or_add_unitable(unitable *table, int var_index, int low, int high);

#endif