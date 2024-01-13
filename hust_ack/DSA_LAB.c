#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct contest{
    char userID[10];
    char problemID[4];
    char timePoint[9];
    char status[3];
    int point;
}contest;

int profileCount = 0;
int so_ket_qua = 0;

int main(){
    contest log[MAX];
    int ket_qua[MAX];
    while(1){
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
        strcpy(log[profileCount].userID, token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(log[profileCount].problemID, token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(log[profileCount].timePoint, token);

        token = strtok_r(NULL, " ", &saveptr);
        strcpy(log[profileCount].status, token);

        token = strtok_r(NULL, " ", &saveptr);
        log[profileCount].point = atoi(token);

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

        if(strcmp(cmd, "?total_number_submissions") == 0){
            ket_qua[so_ket_qua] = profileCount;
        }

        if(strcmp(cmd, "?number_error_submission") == 0){
            int errCount = 0;

            for(int i = 0; i < profileCount; i++){
                if(strcmp(log[i].status, "ERR") == 0){
                    errCount++;
                }
            }

            ket_qua[so_ket_qua] = errCount;                
        }

        if(strcmp(cmd, "?number_error_submission_of_user") == 0){
            int userErrCount = 0;
            char username[4];

            token = strtok_r(NULL," ", &saveptr);
            strcpy(username, token);

            for(int i = 0; i < profileCount; i++){
                if(strcmp(log[i].status, "ERR") == 0 && strcmp(log[i].userID, username) == 0){
                    userErrCount++;
                }
            }

            ket_qua[so_ket_qua] = userErrCount;         
        }

         if(strcmp(cmd, "?total_point_of_user") == 0){
            int totalPoint = 0;
            char username[4];
            char problemID[50];
            int highestScore;

            // Create a map to store the highest score for each problem for the user
            struct {
                char problemID[50];
                int highestScore;
            } problemScores[profileCount];

            int problemCount = 0;

            token = strtok_r(NULL," ", &saveptr);
            strcpy(username, token);

            for(int i = 0; i < profileCount; i++){
                if(strcmp(log[i].userID, username) == 0){
                    // Check if we have seen this problem before
                    int found = 0;
                    for(int j = 0; j < problemCount; j++){
                        if(strcmp(problemScores[j].problemID, log[i].problemID) == 0){
                            found = 1;
                            // Update the highest score for this problem
                            if(log[i].point > problemScores[j].highestScore){
                                problemScores[j].highestScore = log[i].point;
                            }
                            break;
                        }
                    }

                    // If we haven't seen this problem before, add it to the map
                    if(!found){
                        strcpy(problemScores[problemCount].problemID, log[i].problemID);
                        problemScores[problemCount].highestScore = log[i].point;
                        problemCount++;
                    }
                }
            }

            // Sum up the highest scores for all problems
            for(int i = 0; i < problemCount; i++){
                totalPoint += problemScores[i].highestScore;
            }

            ket_qua[so_ket_qua] = totalPoint;         
        }

        if(strcmp(cmd, "?number_submission_period") == 0){
            int totalSubmissions = 0;
            char fromTimePeriod[9];
            char toTimePeriod[9];

            token = strtok_r(NULL," ", &saveptr);
            strcpy(fromTimePeriod, token);

            token = strtok_r(NULL," ", &saveptr);
            strcpy(toTimePeriod, token);

            for(int i = 0; i < profileCount; i++){
                if(strcmp(log[i].timePoint, fromTimePeriod) > 0 && strcmp(log[i].timePoint, toTimePeriod) < 0){
                    totalSubmissions++;
                }
            }

            ket_qua[so_ket_qua] = totalSubmissions;         
        }

        so_ket_qua++;
    }
    
    for(int i = 0; i < so_ket_qua; i++){
        printf("%d\n", ket_qua[i]);
    }

    return 0;
}