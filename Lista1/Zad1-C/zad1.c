#include <stdio.h>
#include "c_library.h"

int main() {
    int option;
    int a, b, c;
    int result;
    DiophanticResult resultSrtuct;

    printf("Library in C\n");
    while (1) {
        printf("1. Factorial loop\n2. Factorial recursive\n3. GCD loop\n4. GCD recursive\n5. Diophantic loop\n6. Diophantic recursive\n7. Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Input n\n");
            scanf("%d", &a);
            result = factorial_loop(a);
            printf("Result: %d\n", result);
            break;
        case 2:
            printf("Input n\n");
            scanf("%d", &a);
            result = factorial_recursive(a);
            printf("Result: %d\n", result);
            break;
        case 3:
            printf("Input a and b\n");
            scanf("%d %d", &a, &b);
            result = gcd_loop(a, b);
            printf("Result: %d\n", result);
            break;
        case 4:
            printf("Input a and b\n");
            scanf("%d %d", &a, &b);
            result = gcd_recursive(a, b);
            printf("Result: %d\n", result);
            break;
        case 5:
            printf("Input a, b and c\n");
            scanf("%d %d %d", &a, &b, &c);
            resultSrtuct = diophantic_loop(a, b, c);
            if(resultSrtuct.r == 0) {
                printf("Result: x = %d, y = %d\n", resultSrtuct.x, resultSrtuct.y);
            } else if(resultSrtuct.r == 1) {
                printf("No results\n");
            } else if(resultSrtuct.r == 1) {
                printf("Infinite number of results\n");
            } else {
                printf("Error\n");
            }
            break;
        case 6:
            printf("Input a, b and c\n");
            scanf("%d %d %d", &a, &b, &c);
            resultSrtuct = diophantic_recursive(a, b, c);
            if(resultSrtuct.r == 0) {
                printf("Result: x = %d, y = %d\n", resultSrtuct.x, resultSrtuct.y);
            } else if(resultSrtuct.r == 1) {
                printf("No results\n");
            } else if(resultSrtuct.r == 1) {
                printf("Infinite number of results\n");
            } else {
                printf("Error\n");
            }
            break;
        case 7:
            return 0;
        default:
            break;
        }
    }
}