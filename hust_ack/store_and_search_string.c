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
    if (p == NULL) return makeNode(i_name);  // If the list is empty, create a new node.
    
    Node* temp = p;
    while (temp->rightSibling != NULL) {  // Traverse the list to the last node.
        temp = temp->rightSibling;
    }
    
    temp->rightSibling = makeNode(i_name);  // Add the new node at the end of the list.
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
    char command[512];
    char key[512];

    while (1){
        scanf("%s", command);

        if(strcmp(command, "*") == 0)
            break;
        
         if (root == NULL) {
            root = makeNode(command);
        }

        addChild(root, command);
        }

    while (1){
        scanf("%s", command);
        if(strcmp(command, "*") == 0)
            break;

        scanf("%s", key);
        if(strcmp(command, "find") == 0){
            Node* wanted = find(root, key);

            if(wanted != NULL)
                printf("1\n");
            else
                printf("0\n");
        }
        else if(strcmp(command, "insert") == 0){
            
        }
    }
    
    printTree(root);
    freeTree(root);
    return 0;
}