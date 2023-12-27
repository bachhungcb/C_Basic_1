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

    Node* lefResult = find(r->rightSibling, i_name);

    if(lefResult != NULL)
        return lefResult;

    return find(r->rightSibling, i_name);
}

Node* addLast(Node* p, char* i_name){
    if(p == NULL) return makeNode(i_name);
    p->rightSibling = addLast(p->rightSibling, i_name);
    return p;
}

void addChild(char* child, char* parent){
    Node* r = find(root, parent);
    if(r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild, child);
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

int main(){
    root = makeNode("Newman");
    addChild("Peter", "Newman");
    addChild("Michael", "Thomas");
    addChild("John", "David");
    addChild("Paul", "Mark");
    addChild("Stephan", "Mark");
    addChild("Pierre", "Thomas");
    addChild("Mark", "Newman");
    addChild("Bill", "David");
    addChild("David", "Newman");
    addChild("Thomas", "Mark");
    printTree(root);
    printf("The number of children for %s is %d.\n", "Newman", count(root));
    freeTree(root);
    return 0;
}