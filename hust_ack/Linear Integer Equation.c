#include <stdio.h>

void generate_ordered_collections(int n, int M, int current_collection[], int index) {
    if (n == 0 && M == 0) {
        // Print the current collection
        for (int i = 0; i < index - 1; ++i) {
            printf("%d ", current_collection[i]);
        }
        if (index > 0) {
            printf("%d", current_collection[index - 1]);
        }
        printf("\n");
        return;
    }

    if (n <= 0 || M <= 0) {
        return;
    }

    for (int i = 1; i <= M; ++i) {
        // Update the current collection
        current_collection[index] = i;

        // Recursively generate collections with updated parameters
        generate_ordered_collections(n - 1, M - i, current_collection, index + 1);
    }
}

int main() {
    int n, M;

    // Input values for n and M
    scanf("%d", &n);
    scanf("%d", &M);

    // Initialize an array to store the current collection
    int current_collection[n];

    // Generate ordered collections
    generate_ordered_collections(n, M, current_collection, 0);

    return 0;
}
