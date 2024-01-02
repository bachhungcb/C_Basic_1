#include <stdio.h>

int main() {
    int a, b, c; // a and b are the capacities of the two jugs, c is the desired amount of water
    scanf("%d %d %d", &a, &b, &c);

    // If the desired amount of water can be obtained by a simple transfer between the two jugs,
    // then return the number of steps required
    if (a >= c && b >= c) {
        printf("%d", c / a + c / b);
        return 0;
    }

    // If the desired amount of water cannot be obtained by a simple transfer,
    // then find the minimum number of steps required by transferring as much water as possible
    // between the two jugs using the pump
    int steps = 0;
    int water = 0;

    while (water != c) {
        steps++;
        // Fill the first jug
        if (water + a <= b)
            water += a;
        else
            water = b;

        if (water == c) break;

        steps++;
        // Empty the second jug
        water -= b;
    }

    printf("%d", steps + 1);
    return 0;
}
