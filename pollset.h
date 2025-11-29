

#ifndef DILL_POLLSET_INCLUDED
#define DILL_POLLSET_INCLUDED

/* User overloads. */
#if defined DILL_EPOLL
#include "epoll.h.inc"
#elif defined DILL_KQUEUE
#include "kqueue.h.inc"
#elif defined DILL_POLL
#include "poll.h.inc"
/* Defaults. */
#elif defined HAVE_EPOLL
#include "epoll.h.inc"
#elif defined HAVE_KQUEUE
#include "kqueue.h.inc"
#else
#include "poll.h.inc"
#endif

int dill_ctx_pollset_init(struct dill_ctx_pollset *ctx);
void dill_ctx_pollset_term(struct dill_ctx_pollset *ctx);

/* Add waiting for an in event on the fd to the list of current clauses. */
int dill_pollset_in(struct dill_fdclause *fdcl, int id, int fd);

/* Add waiting for an out event on the fd to the list of current clauses. */
int dill_pollset_out(struct dill_fdclause *fdcl, int id, int fd);

/* Drop any cached info about the file descriptor. */
int dill_pollset_clean(int fd);

/* Wait for events. 'timeout' is in milliseconds. Return 0 if the timeout expired or
  1 if at least one clause was triggered. */
int dill_pollset_poll(int timeout);

#endif

