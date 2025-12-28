#include "../utils/utils.h"
#include <stdio.h>

void echo(Strings *strings) {
  for (size_t i = 0; i < strings->len - 1; ++i) {
    printf("%s", strings->items[i]);
    if (i < strings->len - 1) {
      printf(" ");
    }
  }
  printf("\n");
}
