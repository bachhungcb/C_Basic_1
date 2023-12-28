#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;
Node* root;

Node* makeNode(char* i_name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,i_name);
    newNode->leftMostChild=NULL;
    newNode->rightSibling=NULL;
    return newNode;
}

Node* find(Node* r, char* i_name){
    if(r == NULL)return NULL;
    if(strcmp(r->name, i_name) == 0) return r;

    Node* lefResult = find(r->leftMostChild, i_name);

    if(lefResult != NULL)
        return lefResult;

    return find(r->rightSibling, i_name);
}

Node* addLast(Node* p, char* i_name) {
    if (p == NULL) return makeNode(i_name);
    Node* temp = p;
    while (temp != NULL) {
        if (strcmp(temp->name, i_name) == 0) return p; // Check for duplicate
        if (temp->rightSibling == NULL) {
            temp->rightSibling = makeNode(i_name);
            return p;
        }
        temp = temp->rightSibling;
    }
    return p;
}

void addChild(Node* child, Node* parent){
   if(parent == NULL) return;
    parent->leftMostChild = addLast(parent->leftMostChild, child->name);
}

 void freeTree(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;

    while(p != NULL){
        Node* sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }

    //printf("free node %s\n",r->name); free(r);
    r = NULL;
 }


void processFind(){
    char name[256];     scanf("%s", name);
    Node* p = find(root, name);
    if(p == NULL) printf("Khong tim thay node: %s\n", name);
    else printf("Tim thay Node: %s\n", name);
}

int processFindChild(){
    char name[256];     scanf("%s", name);
    int childCount = 0;
    Node* p = find(root, name);
    if(p == NULL) return 0;
    else{
        Node* q = p->leftMostChild;
        while(q != NULL){
            childCount++;     q=q->rightSibling;
        }
    }

    return childCount;
}

int height(Node* p){
    if(p == NULL)return 0;
    int maxH = 0;

    Node* q = p->leftMostChild;
    while(q != NULL){
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

void printTree(Node* r){
    if(r == NULL) return;
    printf("%s->", r->name);
    Node* p = r->leftMostChild;
    
    while(p!=NULL){
        printf("%s->", p->name);
        p=p->rightSibling;
    }

    printf("\n");
    p = r->leftMostChild;
    while(p!=NULL){
        printTree(p);
        p=p->rightSibling;
    }
}


void inOrder(Node* r) {
    if(r == NULL) return;
    Node *p = r->leftMostChild;
    inOrder(p);
    printf("%s->", r->name);

    if(p != NULL)
        p = p->rightSibling;

    while(p != NULL){
        inOrder(p);
        p = p->rightSibling;
    }
}

int count (Node *r){
    if(r == NULL) return 0;
    int cnt = 1;
    Node* q = r->leftMostChild;

    while(q != NULL){
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}

int countDirectChildren(Node *r){
    if(r == NULL) return 0;
    int cnt = 0;
    Node* q = r->leftMostChild;

    while(q != NULL){
        cnt++;
        q = q->rightSibling;
    }
    return cnt;
}


int main() {
    root = NULL;
    char child[256];
    char parent[256];
    char choice[256];
    char name[256];
    while (strcmp(child, "***") != 0 || strcmp(parent, "***") != 0)  {
        scanf("%s %s", child, parent);
        printf("Child: %s\n", child);
        printf("parent: %s\n", parent);
        Node* childNode = makeNode(child);
        Node* parentNode = find(root, parent);

        if (parentNode == NULL) {
            root = makeNode(parent);
            parentNode = root;
        }
        addChild(childNode, parentNode);
    }

    while (strcmp(choice, "***") != 0 || strcmp(name, "***") != 0) {
        scanf("%s %s", choice, name);
        printf("name: %s\n", name);
        Node* wanted = find(root, name);

        if (strcmp(choice, "descendants") == 0) {
            printf("%d\n", count(wanted));
        }

        if (strcmp(choice, "generation") == 0) {
            printf("%d\n", height(wanted));
        }
    }

    freeTree(root);
    return 0;
}