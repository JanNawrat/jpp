#include <stdio.h>
#include "lib.h"

int main() {
    DiophanticResult res = diophantic_loop(240, 46, 28);
    printf("%d %d %d\n", res.r, res.x, res.y);
    // printf("%d\n", factorial_loop(4));
    return 0;
}