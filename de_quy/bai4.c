#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char key;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode(char key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isKeyPresent(char key) {
    struct Node *current = root;
    while (current != NULL) {
        if (key == current->key) {
            return 1; // Key is present
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return 0; // Key is not present
}

void insert(char key) {
    if (isKeyPresent(key)) {
        return;
    }

    struct Node *node = createNode(key);
    if (root == NULL) {
        root = node;
    } else {
        struct Node *current = root;
        struct Node *parent = NULL;
        while (current != NULL) {
            parent = current;
            if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (key < parent->key) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
}

void del(char key) {
    struct Node *current = root;
    struct Node *parent = NULL;
    while (current != NULL && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == NULL) {
        return;
    }

    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    } else if (current->left != NULL && current->right == NULL) {
        if (parent == NULL) {
            root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        free(current);
    } else if (current->left == NULL && current->right != NULL) {
        if (parent == NULL) {
            root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        free(current);
    } else {
        struct Node *successor = current->right;
        struct Node *successorParent = current;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        current->key = successor->key;
        if (successorParent == current) {
            successorParent->right = successor->right;
        } else {
            successorParent->left = successor->right;
        }
        free(successor);
    }
}

void reverseInorder(struct Node *node) {
    if(node == NULL){
        return;
    }
    reverseInorder(node->right);
    printf("%c ", node->key);
    reverseInorder(node->left);
}


int main() {
    char input[100];
    char *token;
    insert('a');
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '#') {
            break;
        }
        token = strtok(input, " \n");
        while (token != NULL) {
            if (strcmp(token, "insert") == 0) {
                token = strtok(NULL, " \n");
                insert(token[0]);
            } else if (strcmp(token, "del") == 0) {
                token = strtok(NULL, " \n");
                del(token[0]);
            }
            token = strtok(NULL, " \n");
        }
    }
    if(root == NULL) {
        printf("NULL");
    }else{
        reverseInorder(root);
    }
    printf("\n");

    return 0;
}