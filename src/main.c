#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "../include/session.h"
#include "../include/region.h"

int main(const int argc, const char *argv[])
{
    Session *session = session_init();

    char *line;
    char prompt[64];

    while (1) {
        if (session->pid != -1) {
            snprintf(prompt, sizeof(prompt), "memz (%d:%s)> ", session->pid, session->pname);
        } else {
            snprintf(prompt, sizeof(prompt), "memz> ");
        }

        line = readline(prompt);

        if (line && *line) add_history(line);
        if (line == NULL) {
            break;
        }

        char *cmd = strtok(line, " ");
        if (cmd == NULL) {
            free(line);
            continue;
        }

        if (strcmp(cmd, "help") == 0) {
            ;
        }

        if (strcmp(cmd, "print") == 0) {
            session_print(session);
        }

        if (strcmp(cmd, "attach") == 0) {
            char *arg = strtok(NULL, " ");

            char *endptr;
            size_t p = strtoul(arg, &endptr, 10);

            if (arg == endptr || *endptr != '\0') {
                fprintf(stderr, "error: invalid pid '%s'\n", arg);
            }

            pid_t pid = (pid_t)p;

            if (session_attach_pid(session, pid) != 0) {
                fprintf(stderr, "could not attach to process %d\n", pid);
            } else {
                printf("attached to pid %d (%s)\n", pid, session->pname);
                region_print_maps(session);
            }

        }
    }

    return EXIT_SUCCESS;
}
