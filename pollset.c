

/* Include the poll-mechanism-specific stuff. */

/* User overloads. */
#if defined DILL_EPOLL
#include "epoll.c.inc"
#elif defined DILL_KQUEUE
#include "kqueue.c.inc"
#elif defined DILL_POLL
#include "poll.c.inc"
/* Defaults. */
#elif defined HAVE_EPOLL
#include "epoll.c.inc"
#elif defined HAVE_KQUEUE
#include "kqueue.c.inc"
#else
#include "poll.c.inc"
#endif
