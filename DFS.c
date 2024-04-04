#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};
int visited[MAX];

void dfs(int node, int n) {
    static int isFirst = 1; // To handle the "->" formatting
    if(isFirst) {
        printf("Visited: ");
        isFirst = 0;
    } else {
        printf("->");
    }
    
    printf("%c", 'A' + node); // Convert index to letter
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n = 5;
    int startNode = 0;

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(startNode, n);
    printf("\n"); // New line after the traversal

    return 0;
}
