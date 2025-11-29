

#ifndef DILL_QLIST_INCLUDED
#define DILL_QLIST_INCLUDED

#include "slist.h"
#include "utils.h"

/* Singly-linked list that's first-in-first-out, so it's actually a queue.
   To iterate over the items, use the underlying slist. */

struct dill_qlist {
    struct dill_slist slist;
    struct dill_slist *last;
};

/* Initialize the list. */
static inline void dill_qlist_init(struct dill_qlist *self) {
    dill_slist_init(&self->slist);
    self->last = &self->slist;
}

/* True if the list has no items. */
static inline int dill_qlist_empty(struct dill_qlist *self) {
    return self->slist.next == &self->slist;
}

/* Push an item to the end of the list. */
static inline void dill_qlist_push(struct dill_qlist *self,
      struct dill_slist *item) {
    item->next = &self->slist;
    self->last->next = item;
    self->last = item;
}

/* Pop an item from the beginning of the list. */
static inline struct dill_slist *dill_qlist_pop(struct dill_qlist *self) {
    struct dill_slist *item = self->slist.next;
    self->slist.next = item->next;
    if(item == self->last) self->last = &self->slist;
    return item;
}

#endif

