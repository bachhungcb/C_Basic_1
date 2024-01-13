#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct Node {
    char account[20];
    int money;
    struct Node* next;
} Node;

Node* hashTable[MAX];

unsigned int hash(char* account) {
    unsigned int value = 0;
    for (int i = 0; i < strlen(account); i++) {
        value = value * 31 + account[i];
    }
    return value % MAX;
}

void insert(char* account, int money) {
    unsigned int index = hash(account);
    Node* node = hashTable[index];
    while (node != NULL) {
        if (strcmp(node->account, account) == 0) {
            node->money += money;
            return;
        }
        node = node->next;
    }
    node = (Node*)malloc(sizeof(Node));
    strcpy(node->account, account);
    node->money = money;
    node->next = hashTable[index];
    hashTable[index] = node;
}

int getMoney(char* account) {
    unsigned int index = hash(account);
    Node* node = hashTable[index];
    while (node != NULL) {
        if (strcmp(node->account, account) == 0) {
            return node->money;
        }
        node = node->next;
    }
    return 0;
}

int main(){
     char line[256];
    char *saveptr = NULL;
    char *token;

    while(fgets(line,256,stdin)){
        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        
        if(strcmp(line, "#") == 0){
            break;
        }
        char fromAccount[20], toAccount[20];
        int money;

        token = strtok_r(line, " ", &saveptr);
        strcpy(fromAccount, token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(toAccount, token);

        token = strtok_r(NULL, " ", &saveptr);
        money = atoi(token);

        insert(fromAccount, money);
    }

    while(1){
        char line[256];
        char *saveptr = NULL;
        char *token;
        char cmd[256];

        fgets(line,256,stdin);

        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if(strcmp(line, "#") == 0)
            break;

        token = strtok_r(line, " ", &saveptr);
        strcpy(cmd, token);

        if(strcmp(cmd, "?total_money_transaction_from") == 0){
            char username[20];

            token = strtok_r(NULL, " ", &saveptr);
            strcpy(username, token);

            printf("%d\n", getMoney(username));
        }
    }
    
    return 0;
}