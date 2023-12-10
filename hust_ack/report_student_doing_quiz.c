#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char date[11];
    int count;
} Entry;

int compare(const void *a, const void *b) {
    return strcmp(((Entry *)a)->date, ((Entry *)b)->date);
}

int main() {
    char line[MAX_LINE_LENGTH];
    Entry entries[365];
    int num_entries = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        if (line[0] == '*') {
            break;
        }

        char date[11];
        strncpy(date, line, 10);
        date[10] = '\0';

        int i;
        for (i = 0; i < num_entries; i++) {
            if (strcmp(entries[i].date, date) == 0) {
                entries[i].count++;
                break;
            }
        }

        if (i == num_entries) {
            strcpy(entries[num_entries].date, date);
            entries[num_entries].count = 1;
            num_entries++;
        }
    }

    qsort(entries, num_entries, sizeof(Entry), compare);

    for (int i = 0; i < num_entries; i++) {
        printf("%s %d\n", entries[i].date, entries[i].count);
    }

    return 0;
}
