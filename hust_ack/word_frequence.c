#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[21];
    int count;
    struct Node *left, *right;
} Node;

Node* newNode(char* word) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, word);
    node->count = 1;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, char* word) {
    if (node == NULL) return newNode(word);

    int cmp = strcmp(word, node->word);
    if (cmp < 0)
        node->left = insert(node->left, word);
    else if (cmp > 0)
        node->right = insert(node->right, word);
    else
        node->count++;

    return node;
}

void printInOrder(Node* node) {
    if (node == NULL) return;

    printInOrder(node->left);
    printf("%s %d\n", node->word, node->count);
    printInOrder(node->right);
}

int main() {
    char input[100000];
    Node* root = NULL;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        if (input[0] == '*')
            break;

        char *token = strtok(input, " \n");
        while (token != NULL) {
            root = insert(root, token);
            token = strtok(NULL, " \n");
        }
    }

    printInOrder(root);

    return 0;
}