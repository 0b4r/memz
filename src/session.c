#include <stdlib.h>
#include <stdio.h>

#include "../include/session.h"

Session *init_session()
{
    Session *s = malloc(sizeof(Session));
    if (!s) {
        return NULL;
    }

    s->pid = -1;
    s->regions = NULL;
    s->hits = NULL;
    s->hit_count = 0;
    s->reg_count = 0;
    s->target.data = NULL;
    s->target.tlen = 0;

    return s;
}


void print_session(Session *s)
{
    printf("pid: %d\n", s->pid);
    printf("region count: %zu\n", s->reg_count);
    printf("hit count: %zu\n", s->hit_count);
}
