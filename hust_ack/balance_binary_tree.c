#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* root;

Node* makenode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->right = NULL; p->left = NULL;
    return p;
}