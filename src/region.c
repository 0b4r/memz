#include "../include/session.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>



int region_parse_map(const char *line, MemoryRegion *out)
{
    return -1;
}

int region_init_maps(struct Session *s, size_t init_cap)
{
    return 0;
}

int region_destroy_maps(struct Session *s)
{
    return -1;
}

int region_print_maps(struct Session *s)
{
    if (s && s->regions) {
        printf("start addr\tend addr\tsize\tperms\n");
        for (ssize_t i = 0; i < s->reg_count; i++) {
            printf("0x%" PRIxPTR "\t0x%" PRIxPTR "\t%zu\t%s\n",
                    s->regions[i].s_addr, s->regions[i].e_addr,
                    s->regions[i].size, s->regions[i].perms);
        }

        return 0;
    }
    return -1;
}
