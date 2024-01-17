#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WEBS 10000

typedef struct web {
    char date[11];
    char timePoint[9];
    char inforType[5];
    int inforID;
    char noti[50];
}web;


int processLine(web *log, int i, FILE *fp){
    char line[256];
    char *token;

        fgets(line, 256, stdin);

        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if(strcmp(line, "*") == 0)
            return 0;
        
        token = strtok(line, " ");
        if(token != NULL){
            strcpy(log[i].date, token);
        }

        token = strtok(NULL, " ");
        if(token != NULL){
            strcpy(log[i].timePoint, token);
        }

        token = strtok(NULL, " ");
        if(token != NULL){
            if(strcmp(token, "INFO") == 0){
                strcpy(log[i].inforType, token);
                
                token = strtok(NULL, " ");
                log[i].inforID = atoi(token);

                token = strtok(NULL,"\0");
                strcpy(log[i].noti, token);
            }else{
                strcpy(log[i].inforType, token);
                log[i].inforID = 0;

                token = strtok(NULL, "\0");
                strcpy(log[i].noti, token);
            }
        }
        return 1;
}

int compareLogData(const void *a, const void *b){
    web *s1 = (web *)a;
    web *s2 = (web *)b;
    int i = 0; 
    char *status1, *status2;
    char *time1, *time2;
    char *content1, *content2;
    int error1,error2;

    error1 = s1->inforID;
    error2 = s2->inforID;

    status1 = s1->inforType;
    status2 = s2->inforType;

    if(error1 < error2){
        return -1;
    }else{
        if(strcmp(status1, status2) == 0){

            time1 = s1->timePoint;
            time2 = s2->timePoint;

            if(strcmp(time1, time2) == 0){

                content1 = s1->noti;
                content2 = s2->noti;

                if(strcmp(content1, content2) != 0)
                    return strcmp(content1, content2);
            }else{
                return strcmp(time1,time2);
            }
        
        }
        else{
            return strcmp(status1, status2);
        }
    }
}

int main() {
    web *log = malloc(MAX_WEBS * sizeof(web));
    int i = 0;
    while(1){
        if(!processLine(log, i, stdin)){
            break;
        };
        i++;
    }

    qsort(log, i, sizeof(web), compareLogData);

    for(int j = 0; j < i; j++){
        if(log[j].inforID == 0){
            printf("%s %s %s %s\n", log[j].date, log[j].timePoint, log[j].inforType, log[j].noti);
        }else{
            printf("%s %s %s %d %s\n", log[j].date, log[j].timePoint, log[j].inforType, log[j].inforID, log[j].noti);
        }
    }
    free(log);
    return 0;
}