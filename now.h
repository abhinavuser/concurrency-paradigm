

#ifndef DILL_NOW_INCLUDED
#define DILL_NOW_INCLUDED

#include <stdint.h>

#if defined __APPLE__
#include <mach/mach_time.h>
#endif

struct dill_ctx_now {
#if defined __APPLE__
    mach_timebase_info_data_t mtid;
#endif
#if defined(__x86_64__) || defined(__i386__)
    int64_t last_time;
    uint64_t last_tsc;
#endif
};

int dill_ctx_now_init(struct dill_ctx_now *ctx);
void dill_ctx_now_term(struct dill_ctx_now *ctx);

/* Same as dill_now() except that it doesn't use the context.
   I.e. it can be called before calling dill_ctx_now_init(). */
int64_t dill_mnow(void);

#endif

