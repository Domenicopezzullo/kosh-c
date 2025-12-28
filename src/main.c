#include "echo/echo.h"
#include "exit/exit.h"
#include "which/which.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  signal(SIGINT, SIG_IGN);
  char *line = NULL;
  char *split_line;
  size_t size = 0;
  ssize_t read;
  while (1) {
    printf("$> ");
    read = getline(&line, &size, stdin);
    if (read == -1) {
      printf("\n");
      break;
    };
    if (read > 0 && line[read - 1] == '\n') {
      line[read - 1] = '\0';
    }
    split_line = strtok(line, " ");
    if (split_line == NULL)
      continue;
    if (strcmp(split_line, "exit") == 0) {
      char *next_token;
      if ((next_token = strtok(NULL, " ")) == NULL) {
        exit_shell(line, "0");
      }
      exit_shell(line, next_token);
    } else if (strcmp(split_line, "echo") == 0) {
      char *next_token;
      Strings strings = {0};
      while ((next_token = strtok(NULL, " ")) != NULL) {
        strings_append(&strings, next_token);
      }
      echo(&strings);
      free(strings.items);
    } else if (strcmp(split_line, "which") == 0) {
      char *next_token;
      if ((next_token = strtok(NULL, " ")) != NULL) {
        which(next_token);
      } else
        fprintf(stderr, "which: Usage which <program>\n");
    }
  }
  free(line);
}
