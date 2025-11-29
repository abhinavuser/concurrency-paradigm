

#ifndef DILL_RBTREE_INCLUDED
#define DILL_RBTREE_INCLUDED

#include <stddef.h>
#include <stdint.h>

struct dill_rbtree_item {
    int red;
    struct dill_rbtree_item *left;
    struct dill_rbtree_item *right;
    struct dill_rbtree_item *up;
    int64_t val;
};

struct dill_rbtree {
    struct dill_rbtree_item root;
    struct dill_rbtree_item nil;
};

/* Initialize the tree. */
void dill_rbtree_init(struct dill_rbtree *self);

/* Returns 1 if there are no items in the tree. 0 otherwise. */
int dill_rbtree_empty(struct dill_rbtree *self);

/* Insert an item into the tree & set its value to 'val' */
void dill_rbtree_insert(struct dill_rbtree *self, int64_t val,
    struct dill_rbtree_item *item);

/* Remove an item from a tree. */
void dill_rbtree_erase(struct dill_rbtree *self, struct dill_rbtree_item *item);

/* Return an item with the lowest value. If there are no items in the tree, NULL
   is returned. */
struct dill_rbtree_item *dill_rbtree_first(struct dill_rbtree *self);

/* Iterate through the tree. Items are returned starting with those with
   the lowest values and ending with those with the highest values. Items with
   equal values are returned in no particular order. If 'it' points to the
   last item, NULL is returned. */
struct dill_rbtree_item *dill_rbtree_next(struct dill_rbtree *self,
    struct dill_rbtree_item *it);

#endif
