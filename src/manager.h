#ifndef MANAGER_H
#define MANAGER_H

#include <stdbool.h>
#include "base.h"
#include "decnode.h"
#include "comptable.h"
#include "unitable.h"

// Data structures
typedef struct manager{
    uint var_count;
    uint max_cache_size;
    unitable *unitable;
    comptable *comptable;
} manager;

//Methods
uint get_free_node(manager* manager);
uint* get_one(manager* manager);
uint* get_zero(manager* manager);
uint* and(manager* manager, uint* f, uint* g);
uint* or(manager* manager, uint* f, uint* g);
uint* not(manager* manager, uint* f);
uint* xor(manager* manager, uint* f, uint* g);
bool equiv(manager* manager, uint* f, uint* g);
bool is_const(manager* manager, uint* f);
uint* ite(manager* manager, uint* f, uint* g, uint* h);

#endif