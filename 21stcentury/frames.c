#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 3;
    int b = 2;
    printf("%d + %d = %d", a, b, add(3, 2));
}
