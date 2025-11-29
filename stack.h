

#ifndef DILL_STACK_INCLUDED
#define DILL_STACK_INCLUDED

#include <stddef.h>

#include "slist.h"

/* A stack of unused coroutine stacks. This allows for extra-fast allocation
   of a new stack. The LIFO nature of this structure minimises cache misses.
   When the stack is cached its dill_qlist_item is placed on its top rather
   then on the bottom. That way we minimise page misses. */
struct dill_ctx_stack {
    int count;
    struct dill_slist cache;
};

int dill_ctx_stack_init(struct dill_ctx_stack *ctx);
void dill_ctx_stack_term(struct dill_ctx_stack *ctx);

/* Allocates new stack. Returns pointer to the *top* of the stack.
   For now we assume that the stack grows downwards. */
void *dill_allocstack(size_t *stack_size);

/* Deallocates a stack. The argument is pointer to the top of the stack. */
void dill_freestack(void *stack);

#endif
