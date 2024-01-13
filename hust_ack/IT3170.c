#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX = 100;

typedef struct contest{
    char fromAccount[20];
    char toAccount[20];
    int money;
    char timePoint[9];
    char ATM[3];
}contest;

int profileCount = 0;

int main(){
    contest *log = (contest*)malloc(MAX * sizeof(contest));

    while(1){
        char line[256];
        char *saveptr = NULL;
        char *token;
        fgets(line,256,stdin);

        if(profileCount >= MAX){
            MAX *= 2;
            log = realloc(log, MAX * sizeof(contest));
        }

        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        
        if(strcmp(line, "#") == 0){
            break;
        }
        token = strtok_r(line, " ", &saveptr);
        strcpy(log[profileCount].fromAccount, token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(log[profileCount].toAccount, token);

        token = strtok_r(NULL, " ", &saveptr);
        log[profileCount].money = atoi(token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(log[profileCount].timePoint, token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(log[profileCount].ATM, token);

        profileCount++;
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
            int sum = 0;

            token = strtok_r(NULL, " ", &saveptr);
            strcpy(username, token);

            for(int i = 0; i < profileCount; i++){
                if(strcmp(log[i].fromAccount, username) == 0)
                    sum += log[i].money;
            }
            printf("%d\n",sum);
        }

    }
    
    free(log);
    return 0;
}