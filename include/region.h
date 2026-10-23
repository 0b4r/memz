#ifndef REGION_H
#define REGION_H

#include <stdint.h>
#include <stdio.h>

#define REG_INIT_CAP 64

typedef struct Session Session;

typedef struct {
    uintptr_t s_addr;
    uintptr_t e_addr;
    size_t size;
    char perms[5];
} MemoryRegion;

int region_parse_map(const char *line, MemoryRegion *out);
int region_init_maps(struct Session *s, size_t init_cap);
int region_print_maps(struct Session *s);
int region_destroy_maps(struct Session *s);

#endif /* region.h */
