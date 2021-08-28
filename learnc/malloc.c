#include <stdio.h>
#include <stdlib.h>

typedef struct { char * name; int age; } person;

int main() {
    person *p = malloc(sizeof(person));
    p->name = "John";
    p->age = 27;
    printf("%s %d\n", p->name, p->age);
    free(p);
}
