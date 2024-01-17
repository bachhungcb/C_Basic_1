#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

typedef struct {
    char key[51];
    struct Node* next;
} Node;

Node* hashTable[MAX];

unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % MAX;
}

Node* createNode(char* key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;
    return newNode;
}

int insert(char* key) {
    unsigned long index = hash(key);
    Node* node = hashTable[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0)
            return 0;
        node = node->next;
    }
    node = createNode(key);
    node->next = hashTable[index];
    hashTable[index] = node;
    return 1;
}

int find(char* key) {
    unsigned long index = hash(key);
    Node* node = hashTable[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0)
            return 1;
        node = node->next;
    }
    return 0;
}

int main() {
    char key[51];
    while (scanf("%s", key) != EOF && key[0] != '*') {
        insert(key);
    }
    char command[10];
    while (scanf("%s%s", command, key) != EOF && command[0] != '*') {
        if (strcmp(command, "find") == 0) {
            printf("%d\n", find(key));
        } else if (strcmp(command, "insert") == 0) {
            printf("%d\n", insert(key));
        }
    }
    return 0;
}