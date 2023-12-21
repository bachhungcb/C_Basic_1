#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head, *tail;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->next = NULL;
    return p;
}

void initQueue(){
    head = NULL;
    tail = NULL;
}

int queueEmpty(){
    return head == NULL && tail == NULL;
}

void PUSH(int v){
    Node* p = makeNode(v);
    if(queueEmpty()){
        head = p;
        tail = p;
    }else{
        tail->next = p;
        tail = p;
    }
}

int POP(){
    int result = 0;
    if(queueEmpty()) return 0;
    
    Node *p = head;
    head = p->next;
    if(head == NULL) tail = NULL;
    result = p->data;
    free(p);
    return result; 
    
}

void print_queue(){
    Node *p = head;
    while(p!=NULL){
        printf("%d->", p->data);
        p = p->next;
    }
}

void emptyQueue(){
    while(head != NULL)
        POP();
}

int main(){
    initQueue();
    int ket_qua[256] ={0};
    int i = 0;
    while(1){
        char choice[256];
        scanf("%s", &choice);

        if(strcmp(choice, "PUSH") == 0){
            int value;
            scanf("%d", &value);
            PUSH(value);
        }

        if(strcmp(choice, "POP") == 0){
            ket_qua[i] = POP();
            i++;
        }

        if(strcmp(choice, "#") == 0){
            break;
        }
    }

    
    for(int j = 0; j<i; j++){
        if(ket_qua[j] == 0)
            printf("NULL\n");
        else
            printf("%d\n", ket_qua[j]);
    }
    emptyQueue();
    return 0;
}