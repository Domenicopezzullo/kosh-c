#include <stdlib.h>
typedef struct {
    char** items;
    size_t cap;
    size_t len;
} Strings;

void strings_append(Strings* strings, char* string) {
    if(strings->len >= strings->cap) {
        strings->cap = (strings->cap == 0) ? 256 : strings->cap * 2;
        strings->items = realloc(strings->items, strings->cap * sizeof(char*));
    }
    strings->items[strings->len++] = string;
}
