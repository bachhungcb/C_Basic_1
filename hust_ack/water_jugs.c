#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 901

int a, b, c;
int visited[MAX][MAX];

typedef struct Node {
    int x, y, dist;
} Node;

typedef struct Queue {
    Node* node;
    struct Queue* next;
} Queue;

Queue* front = NULL;
Queue* rear = NULL;

Node* createNode(int x, int y, int dist) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->dist = dist;
    return newNode;
}

void enqueue(Node* node) {
    Queue* temp = (Queue*)malloc(sizeof(Queue));
    temp->node = node;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

Node* dequeue() {
    if (front == NULL) {
        return NULL;
    }
    Queue* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    Node* node = temp->node;
    free(temp);
    return node;
}

int isTarget(Node* node) {
    return (node->x == c || node->y == c);
}

int isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x <= a && y <= b && !visited[x][y]);
}

int BFS() {
    memset(visited, 0, sizeof(visited));
    Node* start = createNode(0, 0, 0);
    enqueue(start);
    visited[0][0] = 1;

    while (front != NULL) {
        Node* node = dequeue();

        if (isTarget(node)) {
            return node->dist;
        }

        // Fill the first jug
        if (isValid(a, node->y)) {
            enqueue(createNode(a, node->y, node->dist + 1));
            visited[a][node->y] = 1;
        }

        // Fill the second jug
        if (isValid(node->x, b)) {
            enqueue(createNode(node->x, b, node->dist + 1));
            visited[node->x][b] = 1;
        }

        // Empty the first jug
        if (isValid(0, node->y)) {
            enqueue(createNode(0, node->y, node->dist + 1));
            visited[0][node->y] = 1;
        }

        // Empty the second jug
        if (isValid(node->x, 0)) {
            enqueue(createNode(node->x, 0, node->dist + 1));
            visited[node->x][0] = 1;
        }

        // Pour from the first jug to the second jug
        if (node->x > 0 && node->y < b) {
            int x = node->x < b - node->y ? 0 : node->x - (b - node->y);
            int y = node->x + node->y >= b ? b : node->x + node->y;
            if (isValid(x, y)) {
                enqueue(createNode(x, y, node->dist + 1));
                visited[x][y] = 1;
            }
        }

        // Pour from the second jug to the first jug
        if (node->y > 0 && node->x < a) {
            int y = node->y < a - node->x ? 0 : node->y - (a - node->x);
            int x = node->x + node->y >= a ? a : node->x + node->y;
            if (isValid(x, y)) {
                enqueue(createNode(x, y, node->dist + 1));
                visited[x][y] = 1;
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", BFS());
    return 0;
}