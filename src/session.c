#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#include "../include/session.h"

    Session *session_init()
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
    *s->pname = '\0';

    return s;
}


void session_print(Session *s)
{
    printf("pid: %d\n", s->pid);
    printf("region count: %zu\n", s->reg_count);
    printf("hit count: %zu\n", s->hit_count);
}

int session_attach_pid(Session *s, pid_t pid)
{
    return 0;
}

int session_get_pname(pid_t pid, char *out, size_t maxlen)
{
    return 0;
}
