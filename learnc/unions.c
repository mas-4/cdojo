#include <stdio.h>

union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

int main() {
    union intParts parts;
    parts.theInt = 5968145;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
            parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    int theInt = parts.theInt;
}
