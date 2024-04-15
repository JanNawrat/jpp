#include <stdio.h>

typedef struct DiophanticResult {
    int r, x, y;
} DiophanticResult;

extern int factorial_loop(int n);
extern int factorial_recursive(int n);
extern int gcd_loop(int a, int b);
extern int gcd_recursive(int a, int b);
extern DiophanticResult diophantic_loop(int a, int b, int c);
extern DiophanticResult diophantic_recursive(int r0, int r1, int c);

int main() {
    DiophanticResult a = diophantic_recursive(240, 46, 28);
    printf("Hello World!\n");
    printf("%d %d %d\n", a.r, a.x, a.y);
    return 0;
}