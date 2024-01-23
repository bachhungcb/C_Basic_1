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


int height(Node* p){
    if(p == NULL) return 0;
    int maxH = 0;
    Node *q = p->leftMostChild;

    while(q != NULL){
        int h = height(q);
        maxH = maxH < h? h: maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

void processHeight(){
    int name;
    //printf("Nhap vao ten can tim:");
    scanf("%d", &name);
    Node *q = find(root, name);
    if(q == NULL) printf("Khong tim thay ten %d", name);
    else{
        printf("Do cao cua %d la: %d.\n", name, height(q));
    }   
}

int depth(Node* r, int v, int d) {
    if (r == NULL) return -1;
    if (r->data == v) return d;

    int depthValue = -1;

    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling) {
        depthValue = depth(p, v, d + 1);

        if (depthValue != -1) return depthValue;
    }

    return depthValue;
}

void processDepth(){
    int name; 
    scanf("%d", &name);
    int d = depth(root, name, 0);
    if(d != -1) printf("Do sau cua %d la: %d\n", name, d + 1);
    else printf("Khong tim thay node %d.\n", name);
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

        if(strcmp(choice, "Insert") == 0){ // co cu phap la Insert(nut con, nut cha) voi nut con
            int child, parent;             // va nut cha deu la int
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

        if(strcmp(choice, "processHeight") == 0){// de tim do cao cua mot node, ta su dung
            processHeight();                     // cu phap processHeight<gia tri node can tim>
        }

        if(strcmp(choice, "processDepth") == 0){
            processDepth();
        }
    }
    //preOrder(root);

    freeTree(root);
    return 0;
}
