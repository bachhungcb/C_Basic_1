#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 120

// Custom comparison function for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    int n, i;
    char **lines;

    scanf("%d", &n);
    getchar();  // Remove newline character

    // Allocate memory for 'n' pointers to char
    lines = malloc(n * sizeof(char *));
    if(lines == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(i = 0; i < n; i++) {
        // Allocate memory for each line
        lines[i] = malloc(MAX_LENGTH * sizeof(char));
        if(lines[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        fgets(lines[i], MAX_LENGTH, stdin);
        lines[i][strcspn(lines[i], "\n")] = 0;  // Remove newline character
    }

    // Sort the lines in ASCII order
    qsort(lines, n, sizeof(char *), compare);

    for(i = 0; i < n; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);  // Free each line
    }

    free(lines);  // Free the array of pointers

    return 0;
}