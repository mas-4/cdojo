#include <stdio.h>

int main() {
    int a = 1;
    int * pointer_to_a = &a;

    printf("The value of a is %d\n", a);
    printf("The value of a is also %d\n", *pointer_to_a);
    printf("The location of a is %p\n", pointer_to_a);
    printf("The next location after a is %p\n", pointer_to_a+1);
    printf("The value of the location after a is %d\n", *(pointer_to_a+1));

    for (int i=0;i<100;i++) {
        printf("The location %d places after a is %p\n", i, pointer_to_a+i);
        printf("The value at %p is %d\n", pointer_to_a+i, *(pointer_to_a+i));
    }
    return 0;
}
