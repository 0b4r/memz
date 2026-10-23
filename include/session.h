#ifndef SESSION_H
#define SESSION_H

#include <stdint.h>
#include <sys/types.h>

#include "region.h"

typedef struct {
    uint8_t *data;
    size_t tlen;
} Target;

struct Session {
    pid_t pid;
    MemoryRegion *regions;
    size_t reg_count;
    uintptr_t *hits;
    size_t hit_count;
    Target target;
    char pname[64];
};

Session *session_init();
int session_attach_pid(Session *s, pid_t pid);
int session_get_pname(pid_t pid, char *out, size_t maxlen);
void session_destroy(Session **s);
void session_print(Session *s);

#endif /* session.h */
