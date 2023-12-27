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

void addChild(int parent, int child){
    Node* r = find(root, parent);
    if(r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild, child);
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

    r = NULL;
}

void preOrder(Node *r){
    if(r == NULL) return;
    printf("%d ", r->data);
    Node *p = r->leftMostChild;

    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}

void inOrder(Node* r) {
    if(r == NULL) return;
    Node *p = r->leftMostChild;
    inOrder(p);
    printf("%d ", r->data);

    if(p != NULL)
        p = p->rightSibling;

    while(p != NULL){
        inOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(Node *r){
    if(r == NULL)return;
    Node* p = r->leftMostChild;

    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }

    printf("%d ", r->data);
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
            int value;
            scanf("%d", &value);
            root = makeNode(value);
        }

        if(strcmp(choice, "Insert") == 0){
            int child, parent;
            scanf("%d %d", &child, &parent);
            addChild(parent, child);
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
    
    freeTree(root);
    return 0;
}
