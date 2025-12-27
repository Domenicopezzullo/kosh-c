#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
void exit_shell(char* line, char* code) {
    errno = 0;
    int parsed_code = (int)strtol(code, NULL, 10);
    if(errno != 0) {
        printf("Usage: exit code or nothing (0)");
        return;
    }
    free(line);
    exit(parsed_code);
}
