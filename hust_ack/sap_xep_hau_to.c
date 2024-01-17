#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 20

int compare(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    char suffix[MAX_LENGTH + 1];
    scanf("%s", suffix);
    getchar(); // consume '\n'

    char *words[MAX_WORDS];
    int count = 0;

    char word[MAX_LENGTH + 1];
    while (scanf("%s", word) != EOF) {
        if (strlen(word) >= strlen(suffix) && strcmp(word + strlen(word) - strlen(suffix), suffix) == 0) {
            words[count] = malloc(strlen(word) + 1);
            strcpy(words[count], word);
            count++;
        }
    }

    qsort(words, count, sizeof(char*), compare);

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    return 0;
}