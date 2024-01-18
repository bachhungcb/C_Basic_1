/*
The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
<from_account>   <to_account>   <money>   <time_point>   <atm>
In which:
•	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
•	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
•	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
•	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
•	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds)
A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1.
Write a program that process the following queries:
?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>
Input (stdin)
The input consists of 2 blocks of information: the data block and the query block
•	The data block consists of lines:
o	Each line contains the information about a transaction described above
o	The data is terminated by a line containing #
•	The query block consists of lines:
o	Each line is a query described above
o	The query block is terminated by a line containing #
Output (stdout)
•	Print to stdout (in each line) the result of each query described above
Example
Input
T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?total_money_transaction_from T000010010
?total_money_transaction_from T000010030
#
Output
4500
4000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct Node {
    char *account;
    unsigned short int money;
    struct Node* next;
} Node;

Node* hashTable[MAX];

unsigned int hash(char* account) {
    unsigned int value = 0;
    int length = strlen(account);  // Store the length of the string
    for (int i = 0; i < length; i++) {
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
    node->account = strdup(account);  // Allocate memory for the account name
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

void freeHashTable() {
    for (int i = 0; i < MAX; i++) {
        Node* node = hashTable[i];
        while (node != NULL) {
            Node* next = node->next;
            free(node->account);  // Free the memory used by the account name
            free(node);
            node = next;
        }
    }
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
            if (token != NULL) {  // Check if the token is not NULL before copying it
                strcpy(username, token);
            }

            printf("%hu\n", getMoney(username));
        }
    }
    freeHashTable();
    return 0;
}
