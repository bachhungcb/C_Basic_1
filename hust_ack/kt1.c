#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 10000

int compare(const void *a, const void *b) {
    return strncmp(*(char **)a, *(char **)b, 20);
}

int main() {
    char words[MAX_WORDS][20];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    qsort(words, n, sizeof(words[0]), &compare);

    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            printf("%c", tolower(words[i][j]));
        }
        printf("\n");
    }

    return 0;
}
