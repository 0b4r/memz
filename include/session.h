#ifndef SESSION_H
#define SESSION_H

#include <stdint.h>
#include <sys/types.h>

typedef struct {
    uint8_t *data;
    size_t tlen;
} Target;

typedef struct {
    uintptr_t s_addr;
    uintptr_t e_addr;
    size_t size;
    char perms[5];
} MemoryRegion;

typedef struct {
    pid_t pid;
    MemoryRegion *regions;
    size_t reg_count;
    uintptr_t *hits;
    size_t hit_count;
    Target target;
} Session;

Session *init_session();
void destroy_session(Session **s);
void print_session(Session *s);

#endif /* session.h */
