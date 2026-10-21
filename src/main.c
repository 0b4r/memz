#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "../include/session.h"

int main(const int argc, const char *argv[])
{
    Session *session = init_session();

    char *line;

    while ((line = readline("memz> ")) != NULL) {
        if (line) add_history(line);
        if (strcmp(line, "exit") == 0) {
            free(line);
            break;
        }
        if (strcmp(line, "print") == 0) {
            print_session(session);
        }
        free(line);
    }

    return EXIT_SUCCESS;
}
