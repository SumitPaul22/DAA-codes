#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};
int visited[MAX];

void bfs(int startNode, int n) {
    int queue[MAX], front = 0, rear = -1, currentNode;
    
    for(int i = 0; i < n; i++) visited[i] = 0;
    
    visited[startNode] = 1;
    queue[++rear] = startNode;

    printf("Visited: ");
    while(front <= rear) {
        currentNode = queue[front++];
        if(front > 1) printf("->");
        printf("%c", 'A' + currentNode);

        for(int i = 0; i < n; i++) {
            if(adj[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 5;
    int startNode = 0;
    
    bfs(startNode, n);
    
    return 0;
}
