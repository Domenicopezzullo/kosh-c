#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void which(char *program) {
  char *path_env = getenv("PATH");
  if (path_env == NULL) {
    fprintf(stderr, "which: PATH is not set\n");
    return;
  }
  char *path = strdup(path_env);
  if (!path) {
    perror("strdup");
    return;
  }
  char *dirpath = strtok(path, ":");
  while (dirpath) {
    char fullpath[PATH_MAX];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, program);

    if (access(fullpath, X_OK) == 0) {
      printf("%s\n", fullpath);
      free(path);
      return;
    }

    dirpath = strtok(NULL, " ");
  }
  fprintf(stderr, "which: no program %s found in PATH\n", program);
  free(path);
}
