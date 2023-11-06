#include <stdio.h>
#include <stdlib.h>

int steps = 0;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Không thể tạo node mới\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    steps++;
    Node* newNode = createNode(data);
    if(head == NULL || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while(current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    for(int i = 0; i < 1000; i++) {
        head = insertNode(head, rand() % 100);
    }
    printList(head);
    printf("\nSteps: %d", steps);
    return 0;
}
