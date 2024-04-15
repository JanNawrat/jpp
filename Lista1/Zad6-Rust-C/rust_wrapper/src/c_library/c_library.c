#include "c_library.h"

int factorial_loop(int n) {
    int factorial = 1;
    while (n > 1) {
        factorial *= n;
        n -= 1;
    }
    return factorial;
}

int factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int gcd_loop(int a, int b) {
    while (a != 0 && b != 0) {
        if(a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a == 0 ? b : a;
}

int gcd_recursive(int a, int b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else if (a > b) {
        return gcd_recursive(a % b, b);
    } else {
        return gcd_recursive(a, b % a);
    }
}

DiophanticResult diophantic_loop(int r0, int r1, int c) {
    if(r0 == 0 && r1 == 0) {
        return (DiophanticResult){c == 0 ? 2 : 1, 0, 0};
    }

    int q, tmp, s0 = 1, s1 = 0, t0 = 0, t1 = 1;

    while (r1 != 0) {
        q = r0/r1;
        tmp = r1;
        r1 = r0 - r1*q;
        r0 = tmp;  

        tmp = s1;
        s1 = s0 - s1*q;
        s0 = tmp;

        tmp = t1;
        t1 = t0 - t1*q;
        t0 = tmp;
    }

    if (c%r0 != 0) {
        return (DiophanticResult){1, 0, 0};
    }

    return (DiophanticResult){0, s0*c/r0, t0*c/r0};
}

DiophanticResult diophantic_recursive_body(int r0, int r1, int c, int s0, int s1, int t0, int t1) {
    if (r1 == 0) {
        if (r0 == 0) {
            return (DiophanticResult){c == 0 ? 2 : 1, 0, 0};
        }
        if (c%r0 != 0) {
            return (DiophanticResult){1, 0, 0};
        }
        return (DiophanticResult){0, s0*c/r0, t0*c/r0};
    }

    int tmp;
    int q = r0/r1;

    tmp = r1;
    r1 = r0 - r1*q;
    r0 = tmp;  

    tmp = s1;
    s1 = s0 - s1*q;
    s0 = tmp;

    tmp = t1;
    t1 = t0 - t1*q;
    t0 = tmp;

    return diophantic_recursive_body(r0, r1, c, s0, s1, t0, t1);
}

DiophanticResult diophantic_recursive(int a, int b, int c) {
    return diophantic_recursive_body(a, b, c, 1, 0, 0, 1);
}