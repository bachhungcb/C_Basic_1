/*
Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
insert k: insert a new node having key = k into T
preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)

Input
Each line contains a command of three above format
The input is terminated by a line containing #
Output
Write the information of preorder, postorder commands described above

Example
Input
insert 5
insert 9
insert 2
insert 1
preorder
insert 8
insert 5
insert 3
postorder
#

Output
5 2 1 9
1 3 2 8 9 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Node* find(Node* r, int v){
    if(r == NULL) return NULL;
    if(r->data == v) return r;

    Node* leftResult = find(r->left, v);

    if(leftResult != NULL)
        return leftResult;
    
    return find(r->right, v);
}

Node* addLast(Node* p, int v){
    if(p == NULL) return makenode(v);
    if(p->right == NULL){
        p->right = makenode(v);
    }else{
        p->right = addLast(p->right,v);
    }

    return p;
}

Node* insert(Node* node, int v){
    if(node == NULL){
        return makenode(v);
    }

    if(v < node->data)
        node->left = insert(node->left,v);
    else if(v > node->data)
        node->right = insert(node->right, v);

    return node;
}

void printTree(Node* r){
    if(r == NULL) return;
    printf("%d->", r->data);
    Node* p = r->left;
    
    while(p!=NULL){
        printf("%d->", p->data);
        p=p->right;
    }

    printf("\n");
    p = r->left;
    while(p!=NULL){
        printTree(p);
        p=p->right;
    }
}

void freeTree(Node* r){
    if(r == NULL) return;
    
    freeTree(r->left);
    freeTree(r->right);
    
    free(r);
}

void preOrder(Node* r) {
    if(r == NULL) return;
    printf("%d ",r->data);
    preOrder(r->left);
    preOrder(r->right);
 }

void inOrder(Node* r) {
    if(r == NULL) return;
    inOrder(r->left);
    printf("%d ",r->data);
    inOrder(r->right);
}

void postOrder(Node *r){
    if(r == NULL)return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%d ",r->data);
}


int main(){
    char choice[256];
    root = NULL;
    while(1){
        char* token;
        fgets(choice, sizeof(choice), stdin);

        // Remove newline character if present
        if (choice[strlen(choice) - 1] == '\n') {
            choice[strlen(choice) - 1] = '\0';
        }
        token = strtok(choice, " ");

        if(strcmp(token, "#") == 0){
            break;
        }

        if(strcmp(token, "insert") == 0){
            int value;
            
            token = strtok(NULL, " ");
            if(token == NULL) continue;
            value = atoi(token);
            root = insert(root, value);

        }

         if(strcmp(choice, "preorder") == 0){
            preOrder(root);
            printf("\n");
        }

        if(strcmp(choice, "inorder") == 0){
            inOrder(root);
            printf("\n");
        }

        if(strcmp(choice, "postorder") == 0){
            postOrder(root);
            printf("\n");
        }
    }

    freeTree(root);
    return 0;

}
