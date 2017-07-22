typedef struct decnode {
    int var_index;
    int low;
    int high;
    int next;
} decnode;

typedef struct decnodes {
    int slotsCount;
    int slotsSize;
    int nodesCount;
    decnode **slots;
} decnodes;



