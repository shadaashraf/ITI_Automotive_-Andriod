#include <stdio.h>
#include "calculate.h"  
int main() {
    int opt, x, y;

    printf("Enter an option (1-4):\n");
    printf("1. Sum\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");

    scanf("%d", &opt);

    if (opt < 1 || opt > 4) {
        printf("Invalid option\n");
        return 1;
    }

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    switch (opt) {
        case 1:
            printf("Result: %d\n", sum(x, y));
            break;
        case 2:
            printf("Result: %d\n", sub(x, y));
            break;
        case 3:
            printf("Result: %d\n", multi(x, y));
            break;
        case 4:
            if (y == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("Result: %f\n", divided(x, y));
            }
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}

