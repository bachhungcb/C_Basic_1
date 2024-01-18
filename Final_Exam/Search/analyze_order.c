#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMEPOINT_LEN 9
#define MAX_ACCOUNT_LEN 16

typedef struct Node {
    char account[MAX_ACCOUNT_LEN];
    char timePoint[MAX_TIMEPOINT_LEN];
    struct Node* next;
} Node;

Node* addOrder(Node* head, char* account, char* timePoint) {
    Node* newOrder = (Node*)malloc(sizeof(Node));
    strcpy(newOrder->account, account);
    strcpy(newOrder->timePoint, timePoint);
    newOrder->next = head;
    return newOrder;
}

int main() {
    Node* log = NULL;
    int order = 0;

    while(1) {
        char line[256];
        char *saveptr = NULL;
        char *token;

        fgets(line,256,stdin);

        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if(strcmp(line, "#") == 0){
            break;
        }

        token = strtok_r(line, " ", &saveptr);
        char account[MAX_ACCOUNT_LEN];
        strcpy(account, token);

        token = strtok_r(NULL, " ", &saveptr);
        char timePoint[MAX_TIMEPOINT_LEN];
        strcpy(timePoint, token);

        log = addOrder(log, account, timePoint);
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