#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMEPOINT_LEN 9
#define MAX_ACCOUNT_LEN 16
#define HASH_SIZE 100000

typedef struct Node {
    char account[MAX_ACCOUNT_LEN];
    char timePoint[MAX_TIMEPOINT_LEN];
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct HashTable {
    char timePoint[MAX_TIMEPOINT_LEN];
    int count;
    struct HashTable* next;
} HashTable;

HashTable* hashTable[HASH_SIZE];

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % HASH_SIZE;
}

void insertHashTable(char* timePoint) {
    unsigned long index = hash(timePoint);
    HashTable* current = hashTable[index];
    while(current != NULL) {
        if(strcmp(current->timePoint, timePoint) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    HashTable* newEntry = (HashTable*)malloc(sizeof(HashTable));
    strcpy(newEntry->timePoint, timePoint);
    newEntry->count = 1;
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;
}

int getHashTable(char* timePoint) {
    unsigned long index = hash(timePoint);
    HashTable* current = hashTable[index];
    while(current != NULL) {
        if(strcmp(current->timePoint, timePoint) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

Node* addOrder(Node* tail, char* account, char* timePoint) {
    Node* newOrder = (Node*)malloc(sizeof(Node));
    strcpy(newOrder->account, account);
    strcpy(newOrder->timePoint, timePoint);
    newOrder->next = NULL;
    newOrder->prev = tail;
    if (tail != NULL) {
        tail->next = newOrder;
    }
    insertHashTable(timePoint);
    return newOrder;
}

int main() {
    Node* log = NULL;
    Node* tail = NULL;
    int order = 0;

    char line[256];
    while(fgets(line, sizeof(line), stdin) != NULL) {
        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if(strcmp(line, "#") == 0){
            break;
        }

        char *token = strtok(line, " ");
        char account[MAX_ACCOUNT_LEN];
        strcpy(account, token);

        token = strtok(NULL, " ");
        char timePoint[MAX_TIMEPOINT_LEN];
        strcpy(timePoint, token);

        Node* newOrder = addOrder(tail, account, timePoint);
        if (log == NULL) {
            log = newOrder;
        }
        tail = newOrder;
        order++;
    }

    while(1){
        char line[256];
        char *token;
        char cmd[256];

        fgets(line,256,stdin);

        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        token = strtok(line, " ");
        strcpy(cmd, token);

        if(strcmp(cmd, "###") == 0)
            break;

        if(strcmp(cmd, "?number_orders") == 0)
            printf("%d\n", order);

        if(strcmp(cmd, "?number_orders_in_period") == 0){
            char fromTime[9];
            char toTime[9];
            int cnt = 0;

            token = strtok(NULL, " ");
            strcpy(fromTime, token);

            token = strtok(NULL, " ");
            strcpy(toTime, token);

            Node* current = log;
            while(current != NULL){
                if(strcmp(current->timePoint,fromTime) >= 0 && strcmp(current->timePoint, toTime) <= 0){
                    cnt++;
                }
                current = current->next;
            }
            
            printf("%d\n",cnt);
        }

        if(strcmp(cmd, "?number_orders_at_time") == 0){
            char atTime[9];
            int cnt = 0;

            token = strtok(NULL, " ");
            if (token == NULL) {
                fprintf(stderr, "Error: expected a time after '?number_orders_at_time'\n");
                continue;
            }
            strcpy(atTime, token);

            Node* current = log;
            while(current != NULL){
                if(strcmp(current->timePoint,atTime) == 0){
                    cnt++;
                }
                current = current->next;
            }
            
            printf("%d\n",cnt);
        }
    }   

    Node* temp;
    while (log != NULL) {
        temp = log;
        log = log->next;
        free(temp);
    }

    return 0;
}
