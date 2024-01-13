#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
    char value[256];
    struct Node* next;
}Node;

Node *head = NULL;
Node *tail = NULL;

Node* makenode(char *_value){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->value,_value);
    p->next = NULL;
    return p;
}

int insertLast(char* _value){
    Node* p = head;

    while(p != NULL){
        if(strcmp(p->value, _value) == 0){
            return 0;
        }
        p=p->next;
    }

    Node *q = makenode(_value);
    if(head == NULL){
        head = tail = q;
    }else{
        tail->next = q;
        tail = q;
    }
    return 1;
}

int find(char *_value){
    Node* p = head;
    if(p == NULL) return 0;
    while(p != NULL){
        if(strcmp(p->value, _value) == 0){
            return 1;
        }
        p=p->next;
    }
    return 0;
}

int insert(char *_value){
    return insertLast(_value);
}

void freeList(){
    Node *temp;
    while(head != NULL){
        temp = head;
        head = temp->next;
        free(temp);
    }
}

void printList(){
    Node* p = head;
    while(p != NULL){
        printf("%s->", p->value);
        p = p->next;
    }
}

int main(){
    char line[256];
    int i = 0;
    int cnt = 0;
    while(1){
        scanf("%s", line);

        if(strcmp(line, "*") == 0)
            break;

        if(i == 0){
            head = tail =  makenode(line);
            i++;
        }else{
            insertLast(line);
        }
    }

    while(1){
        char parameter[50];
        
        scanf("%s %s", line, parameter);

        if(strcmp(line, "***") == 0)
            break;

        if(strcmp(line, "find") == 0){
            printf("%d\n", find(parameter));
        }   

        if(strcmp(line, "insert") == 0){
            printf("%d\n", insert(parameter));
        }

        cnt++;
    }


    freeList();
    return 0;
}
