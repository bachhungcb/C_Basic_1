#include <stdio.h>
#include <math.h>

void findDistinctSolutions(int a, int b, int c) {
    int discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("NO SOLUTION\n");
        return;
    }

    if (a == 0) {
        printf("NO SOLUTION\n");
        return;
    }

    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);

    if (root1 == root2) {
        printf("%.6f 2\n", root1);
    } else {
        printf("%.6f 1\n", fmin(root1, root2));
        printf("%.6f 1\n", fmax(root1, root2));
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    findDistinctSolutions(a, b, c);

    return 0;
}
