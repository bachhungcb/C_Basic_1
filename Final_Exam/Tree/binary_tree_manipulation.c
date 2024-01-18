#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
    int data;
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;

Node* root;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->leftMostChild = NULL; p->rightSibling = NULL;
    return p;
}

Node* find(Node* r, int v){
    if(r == NULL) return NULL;
    if(r->data == v) return r;
    
    Node* leftResult = find(r->leftMostChild, v);

    if(leftResult != NULL)
        return leftResult;
    
    return find(r->rightSibling, v);
}

Node* addLast(Node* p, int v){
    if(p == NULL) return makeNode(v);
    p->rightSibling = addLast(p->rightSibling, v);
    return p;
}

Node* addLeft(int parent, int left){
    Node* r = find(root, parent);
    if(r == NULL || r->leftMostChild != NULL) return NULL;
    r->leftMostChild = addLast(r->leftMostChild, left);
    return r;
}

Node* addRight(int parent, int right){
    Node* r = find(root, parent);
    if(r == NULL || r->rightSibling != NULL) return NULL;
    r->rightSibling = addLast(r->rightSibling, right);
    return r;
}

void printTree(Node* r){
    if(r == NULL) return;
    printf("%d->", r->data);
    Node* p = r->leftMostChild;
    
    while(p!=NULL){
        printf("%d->", p->data);
        p=p->rightSibling;
    }

    printf("\n");
    p = r->leftMostChild;
    while(p!=NULL){
        printTree(p);
        p=p->rightSibling;
    }
}

void freeTree(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;

    while(p!=NULL){
        Node* sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }

    //printf("Free Node %d\n", r->data); free(r);
    r = NULL;
}

void preOrder(Node* r) {
    if(r == NULL) return;
    printf("%d ",r->data);
    preOrder(r->leftMostChild);
    preOrder(r->rightSibling);
 }

void inOrder(Node* r) {
    if(r == NULL) return;
    inOrder(r->leftMostChild);
    printf("%d ",r->data);
    inOrder(r->rightSibling);
}

void postOrder(Node *r){
    if(r == NULL)return;
    postOrder(r->leftMostChild);
    postOrder(r->rightSibling);
    printf("%d ",r->data);
}


int main(){
    char choice[256];
    root = NULL;
    while(1){
        scanf("%s", choice);

        if(strcmp(choice, "*") == 0){
            break;
        }

        if(strcmp(choice, "MakeRoot") == 0){
            root = makeNode(1);
        }

        if(strcmp(choice, "AddLeft") == 0){
            int left, parent;
            scanf("%d %d", &left, &parent);
            addLeft(parent, left);
        }

        if(strcmp(choice, "AddRight") == 0){
            int right, parent;
            scanf("%d %d", &right, &parent);
            addRight(parent, right);
        }

        if(strcmp(choice, "PreOrder") == 0){
            preOrder(root);
            printf("\n");
        }

        if(strcmp(choice, "InOrder") == 0){
            inOrder(root);
            printf("\n");
        }

        if(strcmp(choice, "PostOrder") == 0){
            postOrder(root);
            printf("\n");
        }
    }
    
    return 0;
}
