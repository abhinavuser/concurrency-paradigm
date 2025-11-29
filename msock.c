

#include <errno.h>
#include <stddef.h>

#define DILL_DISABLE_RAW_NAMES
#include "libdillimpl.h"
#include "utils.h"

dill_unique_id(dill_msock_type);

int dill_msend(int s, const void *buf, size_t len, int64_t deadline) {
    struct dill_msock_vfs *m = dill_hquery(s, dill_msock_type);
    if(dill_slow(!m)) return -1;
    struct dill_iolist iol = {(void*)buf, len, NULL, 0};
    return m->msendl(m, &iol, &iol, deadline);
}

ssize_t dill_mrecv(int s, void *buf, size_t len, int64_t deadline) {
    struct dill_msock_vfs *m = dill_hquery(s, dill_msock_type);
    if(dill_slow(!m)) return -1;
    struct dill_iolist iol = {buf, len, NULL, 0};
    return m->mrecvl(m, &iol, &iol, deadline);
}

int dill_msendl(int s, struct dill_iolist *first, struct dill_iolist *last,
      int64_t deadline) {
    struct dill_msock_vfs *m = dill_hquery(s, dill_msock_type);
    if(dill_slow(!m)) return -1;
    if(dill_slow(!first || !last || last->iol_next)) {
        errno = EINVAL; return -1;}
    return m->msendl(m, first, last, deadline);
}

ssize_t dill_mrecvl(int s, struct dill_iolist *first, struct dill_iolist *last,
      int64_t deadline) {
    struct dill_msock_vfs *m = dill_hquery(s, dill_msock_type);
    if(dill_slow(!m)) return -1;
    if(dill_slow((last && last->iol_next) ||
          (!first && last) ||
          (first && !last))) {
        errno = EINVAL; return -1;}
    return m->mrecvl(m, first, last, deadline);
}

