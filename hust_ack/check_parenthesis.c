#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char val;
    struct Node* next;
}Node;

Node* makeNode(char c){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = c; newNode->next = NULL;
    return newNode;
}

Node* push(Node* h, char c){ 
    Node* newNode = makeNode(c);
    newNode->next = h;
    return newNode;
}

Node* pop(Node* h){
    if(h == NULL)
        return NULL;
    Node* nextNode = h->next;
    free(h);
    return nextNode;
}

int isEmpty(Node* h){
    return h == NULL;
}

int main(){
    char myString[1000];
    scanf("%s", myString);
    Node* head = NULL;
    
    for(int i = 0; myString[i] != '\0'; i++){
        if(myString[i] == '(' || myString[i] == '{' ||myString[i] == '[' ){
            head = push(head, myString[i]);
        }

        if(myString[i] == ')' && head != NULL && head->val == '('){
            head = pop(head);
        }

        if(myString[i] == ']' && head != NULL && head->val == '['){
            head = pop(head);
        }

        if(myString[i] == '}' && head != NULL && head->val == '{'){
            head = pop(head);
        }
    }

    printf("%d", isEmpty(head));
    free(head);
    return 0;
}
