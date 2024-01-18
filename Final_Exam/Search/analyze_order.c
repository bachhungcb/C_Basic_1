/*
Given a dataset about orders raised over the time, each item is under the format:
                                                                                                        <OrderID> <TimePoint>
in which the order <OrderID> (<OrderID> is a string of length from 2 to 15) is raised at time point <TimePoint> (the <TimePoint> is a string of length 8 representing the time point hh:mm:ss, for example, 08:30:14 means 8 hour 30 minutes 14 seconds)
Perform a sequence of queries about the given dataset of 3 categories:
?number_orders: return the number of orders raised 
?number_orders_in_period <FromTimePoint> <ToTimePoint>: return the number of orders raised in the period from time point <FromTimePoint> to time point <ToTimePoint>
?number_orders_at_time <TimePoint>: return the number of orders raised at the time point <TimePoint>

Input
The first block is a sequence of lines (number of lines can be up to 100000), each line contains an information about an order raised with the format above. The first block is terminated with a line containsing the character #
The second line is a sequence of lines (number of lines can be up to 100000), each line contains a query described above. The second line is terminated with a line containing ###

Output
Write in each line, the result of the correspinding query.

Example
Input
ORD0001 18:48:34
ORD0002 15:53:51
ORD0003 08:07:12
ORD0004 04:06:44
ORD0005 05:11:40
ORD0006 00:18:17
ORD0007 05:09:07
ORD0008 18:48:34
ORD0009 02:31:11
ORD0010 18:48:34
#
?number_orders
?number_orders_in_period 03:00:00 06:30:45
?number_orders_at_time 18:48:34
###
Output 
10
3
3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MIN = 10;
#define MAX_TIMEPOINT_LEN 9
#define MAX_ACCOUNT_LEN 16

typedef struct Node {
    char account[MAX_ACCOUNT_LEN];
    char timePoint[MAX_TIMEPOINT_LEN];
}Node;


int main(){
    
    Node *log = (Node*)malloc(MIN * sizeof(Node));
    int order = 0;

    while(1){
        char line[256];
        char *saveptr = NULL;
        char *token;


        fgets(line,256,stdin);

        if(order >= MIN){
            MIN*=2;
            log = realloc(log, MIN * sizeof(Node));
        }

        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        
        if(strcmp(line, "#") == 0){
            break;
        }

        token = strtok_r(line, " ", &saveptr);
        strcpy(log[order].account, token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(log[order].timePoint, token);

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

            for(int i = 0; i < order; i++){
                if(strcmp(log[i].timePoint,fromTime) > 0 && strcmp(log[i].timePoint, toTime) < 0){
                    cnt++;
                }
            }
            
            printf("%d\n",cnt);
        }

        if(strcmp(cmd, "?number_orders_at_time") == 0){
            char atTime[9];
            int cnt = 0;

            token = strtok(NULL, " ");
            strcpy(atTime, token);

            for(int i = 0; i < order; i++){
                if(strcmp(log[i].timePoint,atTime) == 0){
                    cnt++;
                }
            }
            
            printf("%d\n",cnt);
        }
        }   


    return 0;
}
