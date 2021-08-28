#include <stdio.h>

void addone(int *n) { (*n)++; }

typedef struct { int x; int y; } point;

void move(point *p) {
    p->x++;
    p->y++;
}

int main() {
    int n = 0;
    printf("Before: %d\n", n);
    addone(&n);
    printf("After: %d\n", n);
    point p;
    p.x = 23;
    p.y = 92;
    printf("Before (%d,%d)\n", p.x, p.y);
    move(&p);
    printf("After (%d,%d)\n", p.x, p.y);
}
