#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 100000
#define LOAD_FACTOR 0.75

typedef struct {
    int key;
    int exists;
} HashEntry;

typedef struct {
    HashEntry* entries;
    int size;
    int count;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable* hashTable = malloc(sizeof(HashTable));
    hashTable->entries = malloc(size * sizeof(HashEntry));
    hashTable->size = size;
    hashTable->count = 0;

    for (int i = 0; i < size; i++) {
        hashTable->entries[i].key = -1;
        hashTable->entries[i].exists = 0;
    }

    return hashTable;
}

int hash(int key, int size) {
    return key % size;
}



int findKey(HashTable* hashTable, int key) {
    int index = hash(key, hashTable->size);

    while (hashTable->entries[index].key != -1) {
        if (hashTable->entries[index].key == key && hashTable->entries[index].exists) {
            return 1;
        }
        index = (index + 1) % hashTable->size;
    }

    return 0;
}

void resizeHashTable(HashTable* hashTable);

void insertKeyDirectly(HashTable* hashTable, int key) {
    int index = hash(key, hashTable->size);

    while (hashTable->entries[index].key != -1) {
        index = (index + 1) % hashTable->size;
    }

    hashTable->entries[index].key = key;
    hashTable->entries[index].exists = 1;
    hashTable->count++;
}

void resizeHashTable(HashTable* hashTable) {
    int oldSize = hashTable->size;
    HashEntry* oldEntries = hashTable->entries;

    hashTable->size *= 2;
    hashTable->entries = malloc(hashTable->size * sizeof(HashEntry));
    hashTable->count = 0;

    for (int i = 0; i < hashTable->size; i++) {
        hashTable->entries[i].key = -1;
        hashTable->entries[i].exists = 0;
    }

    for (int i = 0; i < oldSize; i++) {
        if (oldEntries[i].exists) {
            insertKeyDirectly(hashTable, oldEntries[i].key);
        }
    }

    free(oldEntries);
}

int main() {
    HashTable* hashTable = createHashTable(INITIAL_SIZE);

    // Read the keys from the first block
    int key;
    while (scanf("%d", &key) == 1) {
        if (key == -1) {
            break;
        }
        insertKeyDirectly(hashTable, key);
    }

    // Process the actions from the second block
    char cmd[25];
    while (1) {
        scanf("%s", cmd);
        if(strcmp(cmd, "***") == 0){
            break;
        }

        scanf("%d", &key);

        if (strcmp(cmd, "find") == 0) {
            printf("%d\n", findKey(hashTable, key));
        } 
        
        else if (strcmp(cmd, "insert") == 0) {
            // Check if the key already exists before inserting
            if (findKey(hashTable, key)) {
                printf("0\n");  // Print 0 if the key already exists
            } else {
                insertKeyDirectly(hashTable, key);
                printf("1\n");  // Print 1 if the key was inserted successfully
            }
        }
    }

    free(hashTable->entries);
    free(hashTable);

    return 0;
}