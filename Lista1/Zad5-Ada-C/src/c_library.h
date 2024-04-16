typedef struct DiophanticResult {
    int r, x, y;
} DiophanticResult;

int factorial_loop(int n);

int factorial_recursive(int n);

int gcd_loop(int a, int b);

int gcd_recursive(int a, int b);

DiophanticResult diophantic_loop(int r0, int r1, int c);

DiophanticResult diophantic_recursive_body(int r0, int r1, int c, int s0, int s1, int t0, int t1);

DiophanticResult diophantic_recursive(int a, int b, int c);