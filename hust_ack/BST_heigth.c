#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node of the binary tree
struct Node {
    int id;
    struct Node* left;
    struct Node* right;
};

// Array to store the nodes
struct Node* nodes[50000];

// Function to create a new node
struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    nodes[id] = newNode; // Store the node in the array
    return newNode;
}

void addLeft(int u, int v) {
    if(nodes[v] != NULL) {
        nodes[v]->left = createNode(u);
    }
}

void addRight(int u, int v) {
    if(nodes[v] != NULL) {
        nodes[v]->right = createNode(u);
    }
}

// Function to compute the height of the tree and check if it is balanced
int isBalanced(struct Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 1;
    }
    
    int leftHeight = 0, rightHeight = 0;
    int isLeftBalanced = isBalanced(root->left, &leftHeight);
    int isRightBalanced = isBalanced(root->right, &rightHeight);
    
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    
    if (abs(leftHeight - rightHeight) <= 1 && isLeftBalanced && isRightBalanced) {
        return 1;
    }
    return 0;
}

int main() {
    struct Node* root = NULL;
    char command[10];
    int u, v;
    
    // Read input commands
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = createNode(u);
        } else if (strcmp(command, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            addLeft(u, v); // Corrected here
        } else if (strcmp(command, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            addRight(u, v); // Corrected here
        } else if (strcmp(command, "*") == 0) {
            break;
        }
    }
    
    // Compute height and check if the tree is balanced
    int height = 0;
    int isTreeBalanced = isBalanced(root, &height);
    
    // Print the output
    printf("%d %d\n", isTreeBalanced, height);
    
    return 0;
}