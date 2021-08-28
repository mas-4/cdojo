```
typedef struct {
    int x;
    int y;
} point;

typedef struct {
    char * brand;
    int model;
} vehicle;

point p;
p.x = 10;
p.y = 5;
printf("%d,%d\n", p.x, p.y);

vehicle mycar;
mycar.brand = "Ford";
mycar.model = 2007;
printf("%s %d\n", mycar.brand, mycar.model);
return 0;

void move(point *p) {
    p->x++; // equivalent (*p).x++;
    p->y++; // equivalent (*p).y++;
}
```

- * operator creates is reference
- & operator dereferences
- But * as a declaration is a pointer declaration (which is produced by &).
