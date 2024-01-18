#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 100000
#define LOAD_FACTOR 0.75
#define PRIME_1 151
#define PRIME_2 163

typedef struct {
    long long int key;
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

int hash(long long int key, int size, int attempt) {
    int hash_a = key % size;
    int hash_b = PRIME_2 - (key % PRIME_2);
    return (hash_a + (attempt * (hash_b + 1))) % size;
}

int findKey(HashTable* hashTable, long long int key) {
    int index = hash(key, hashTable->size, 0);
    int attempt = 0;

    while (hashTable->entries[index].exists) {
        if (hashTable->entries[index].key == key) {
            return 1;
        }
        attempt++;
        index = hash(key, hashTable->size, attempt);
    }

    return 0;
}

void resizeHashTable(HashTable* hashTable);

void insertKeyDirectly(HashTable* hashTable, long long int key) {
    int index = hash(key, hashTable->size, 0);
    int attempt = 0;

    while (hashTable->entries[index].exists) {
        attempt++;
        index = hash(key, hashTable->size, attempt);
    }

    hashTable->entries[index].key = key;
    hashTable->entries[index].exists = 1;
    hashTable->count++;

    // Check the load factor
    float loadFactor = (float)hashTable->count / hashTable->size;
    if (loadFactor > LOAD_FACTOR) {
        // Resize the hash table if the load factor is too high
        resizeHashTable(hashTable);
    }
}

void resizeHashTable(HashTable* hashTable) {
    int oldSize = hashTable->size;
    HashEntry* oldEntries = hashTable->entries;

    // Limit the size of the hash table
    if (hashTable->size < 300000) {
        hashTable->size *= 2;
    }

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
    long long int key;
    while (scanf("%lld", &key) == 1) {
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

        scanf("%lld", &key);

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