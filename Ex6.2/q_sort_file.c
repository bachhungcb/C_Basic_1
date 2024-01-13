#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Profile {
    char first_name[20];
    char last_name[20];
    char birthdate[11];  // Assuming YYYY-MM-DD format
};

int compareProfiles(const void *a, const void *b) {
    // Compare last names first
    int last_name_cmp = strcmp(((struct Profile *)a)->last_name, ((struct Profile *)b)->last_name);

    if (last_name_cmp == 0) {
        // If last names are equal, compare birthdates
        return strcmp(((struct Profile *)a)->birthdate, ((struct Profile *)b)->birthdate);
    }

    return last_name_cmp;
}

void swap(struct Profile *a, struct Profile *b) {
    struct Profile temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Profile arr[], int low, int high) {
    struct Profile pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compareProfiles(&arr[j], &pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(struct Profile arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 5;
    struct Profile profiles[n];

    // Read profiles from file
    FILE *input_file = fopen("profile-5.txt", "r");
    if (input_file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fscanf(input_file, "%10s", profiles[i].first_name);
        fscanf(input_file, "%s", profiles[i].last_name);
        fscanf(input_file, "%s", profiles[i].birthdate);
    }

    fclose(input_file);

    // Perform quicksort on profiles
    quickSort(profiles, 0, n - 1);

    // Write sorted profiles to file
    FILE *output_file = fopen("sorted-output-q.txt", "w");
    if (output_file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(output_file, "%s %s\n%s\n", profiles[i].first_name, profiles[i].last_name, profiles[i].birthdate);
    }

    fprintf(output_file, "#");
    fclose(output_file);

    printf("%d hồ sơ đã được sắp xếp và lưu vào file sorted-output.txt.\n", n);

    return 0;
}
