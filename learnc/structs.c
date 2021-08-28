#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    char * brand;
    int model;
} vehicle;

int main() {
    point p;
    p.x = 10;
    p.y = 5;
    printf("%d,%d\n", p.x, p.y);

    vehicle mycar;
    mycar.brand = "Ford";
    mycar.model = 2007;
    printf("%s %d\n", mycar.brand, mycar.model);
    return 0;
}
