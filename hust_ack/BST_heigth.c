#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node of the binary tree
struct Node {
    int id;
    int height;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addLeft(struct Node* root, int u, int v) {
    if(root == NULL) return;
    if(root->id == v){
        root->left = createNode(u);
        return;
    }
    addLeft(root->left, u, v);
    addLeft(root->right, u ,v);
}

void addRight(struct Node* root, int u, int v) {
    if(root == NULL) return;
    if(root->id == v){
        root->right = createNode(u);
        return;
    }
    addRight(root->right, u, v);
    addRight(root->left, u ,v);
}

// Function to compute the height of the tree
int computeHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int height = 0;
    struct Node* stack[50000];
    int top = -1;
    stack[++top] = root;
    
    while (top >= 0) {
        struct Node* node = stack[top--];
        int leftHeight = (node->left != NULL) ? node->left->height : 0;
        int rightHeight = (node->right != NULL) ? node->right->height : 0;
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        height = (node->height > height) ? node->height : height;
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
    
    return height;
}

// Function to check if the tree is balanced
int isBalanced(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    int leftHeight = computeHeight(root->left);
    int rightHeight = computeHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
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
            addLeft(root, u, v);
        } else if (strcmp(command, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            addRight(root, u, v);
        } else if (strcmp(command, "*") == 0) {
            break;
        }
    }
    
    // Compute height and check if the tree is balanced
    int height = computeHeight(root);
    int isTreeBalanced = isBalanced(root);
    
    // Print the output
    printf("%d %d\n", isTreeBalanced, height);
    
    return 0;
}
