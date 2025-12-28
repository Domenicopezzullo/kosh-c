#include <stdlib.h>
typedef struct {
  char **items;
  size_t cap;
  size_t len;
} Strings;

void strings_append(Strings *strings, char *string);
