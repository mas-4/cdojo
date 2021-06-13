#include <stdio.h>
#include <stdlib.h>

int main() {
    char *repstext = getenv("reps");
    int reps = repstext ? atoi(repstext) : 10;
    char *msg = getenv("msg");
    if (!msg) msg = "Hello.";

    printf("Printing %s %d repstext\n", msg, reps);

    for (int i=0; i < reps; i++) printf("%s\n", msg);
}
