#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int steps;
} Point;

#define MAX 1000

int isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int isExit(int x, int y, int n, int m) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

int findExit(int n, int m, int r, int c, int **maze) {
    int **visited = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        visited[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    Point *queue = (Point *)malloc(n * m * sizeof(Point));
    int front = 0, rear = 0;

    Point start = {r, c, 0};
    queue[rear++] = start;
    visited[r][c] = 1;

    while (front < rear) {
        Point current = queue[front++];

        int x = current.x;
        int y = current.y;
        int steps = current.steps;

        if (isExit(x, y, n, m)) {
            free(queue);
            for (int i = 0; i < n; i++) {
                free(visited[i]);
            }
            free(visited);
            return steps;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, n, m) && maze[newX][newY] == 0 && !visited[newX][newY]) {
                Point next = {newX, newY, steps + 1};
                queue[rear++] = next;
                visited[newX][newY] = 1;
            }
        }
    }

    free(queue);
    for (int i = 0; i < n; i++) {
        free(visited[i]);
    }
    free(visited);

    return -1;
}

int main() {
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);

    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        maze[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    int result = findExit(n, m, r - 1, c - 1, maze);  // Giảm 1 để đối ứng với chỉ số bắt đầu từ 1

    if (result != -1) {
        printf("%d\n", result + 1);
    } else {
        printf("-1\n");
    }

    for (int i = 0; i < n; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}