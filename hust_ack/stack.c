#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *top;

int init_stack(){
    return top != NULL;
}

int stack_is_empty(){
    return top == NULL;
}

Node* makeNode(int v){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->next = NULL;
    return p;
}

void PUSH(int v){
    Node* p = makeNode(v);
     p->next = top;
     top = p;
}

int POP(){
    if(stack_is_empty()) {
        return 0;
    }
    int res = top->data;
    Node* temp = top;
    top = temp->next;
    free(temp);
    return res;
}

void print_list(){
    Node *temp = top;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

void empty_list(){
    while(top!= NULL)
        POP();
}

int main(){
    char choice[256];
    int ket_qua[256];
    int i = 0;
    while (1)
    {
        scanf("%s", choice);

        if(strcmp(choice, "PUSH") == 0){
            int values; 
            scanf("%d", &values);
            PUSH(values);
        }

        if(strcmp(choice, "POP") == 0){
            ket_qua[i] = POP();
            i++;
        }

        if(strcmp(choice, "#") == 0)
            break;
    }

    for (int m = 0; m < i; m++){
        if(ket_qua[m] == 0)
            printf("NULL\n");
        else{    
        printf("%d \n",  ket_qua[m]);
        }
    }
    
    empty_list();
    return 0;
}