#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Profile {
    char first_name[20];
    char last_name[20];
    char birthdate[11];  // Assuming YYYY-MM-DD format
};

void merge(struct Profile arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct Profile L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        // Compare last names first
        if (strcmp(L[i].last_name, R[j].last_name) <= 0) {
            // If last names are equal, compare birthdates
            if (strcmp(L[i].last_name, R[j].last_name) == 0 &&
                strcmp(L[i].birthdate, R[j].birthdate) <= 0) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        } else {
            arr[k] = L[i];
            i++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Profile arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
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

    // Perform merge sort on profiles
    mergeSort(profiles, 0, n - 1);

    // Write sorted profiles to file
    FILE *output_file = fopen("sorted-output.txt", "w");
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
