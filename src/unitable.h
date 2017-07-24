#ifndef UNITABLE_H
#define UNITABLE_H

#include "base.h"
#include "decnode.h"

//Constants
#define MAX_SLOTS_COUNT 65536
#define MIN_SLOT_SIZE 131072

//Data structures
typedef struct unitable {
    //uint **items;
    //uint count;
    //uint shift_size;
    uint slots_size;
    uint slots_count;    
    uint nodes_count;
    decnode **slots;
} unitable;

//Methods
void init_unitable(unitable *table, uint slots_size);
void clear_unitable(unitable *table);
void expand_unitable(unitable *table);
decnode* get_decnode(uint loc);
uint find_or_add_unitable(unitable *table, uint var_index, uint low, uint high);

#endif