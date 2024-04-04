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
    queue[++rear] = startNode; // Enqueue start node

    printf("Visited: ");
    while(front <= rear) { // While queue is not empty
        currentNode = queue[front++]; // Dequeue a vertex
        if(front > 1) printf("->");
        printf("%c", 'A' + currentNode); // Convert index to letter

        for(int i = 0; i < n; i++) {
            if(adj[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i; // Enqueue adjacent nodes
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 5; // Number of vertices
    int startNode = 0; // Starting node for BFS
    
    bfs(startNode, n);
    
    return 0;
}
