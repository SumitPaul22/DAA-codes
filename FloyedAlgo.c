#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

int graph[MAX][MAX] = {
    {0, 10, INF, 17, 3},
    {10, 0, 15, 27, 2},
    {INF, 15, 0, 8, 5},
    {17, 27, 8, 0, 3},
    {3, 2, 5, 3, 0}
};
int i, j, k, n = 5; // n is the number of vertices in the graph

void floydWarshall() {
    // Using k for intermediate vertices
    for (k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of graph[i][j]
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

void printMatrix(int mat[MAX][MAX], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(mat[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("The original matrix:\n");
    printMatrix(graph, n);
    
    floydWarshall();
    
    printf("The shortest distances between every pair of vertices:\n");
    printMatrix(graph, n);
    
    return 0;
}
