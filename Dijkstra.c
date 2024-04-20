#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 9999

struct Edge {
    int source, destination, weight;
};

void printDistance(int distance[], int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (distance[i] == INF)
            printf("%c \t %s\n", (char)(i + 'A'), "INF");
        else
            printf("%c \t %d\n", (char)(i + 'A'), distance[i]);
    }
}

void dijkstra(struct Edge edges[], int V, int E, int source, int distance[]) {
    int visited[MAX] = {0}; // Initialize visited array
    distance[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        // Find the vertex with the minimum distance value
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || distance[i] < distance[u]))
                u = i;
        }
        visited[u] = 1;
        
        for (int j = 0; j < E; j++) {
            int v = edges[j].destination;
            int w = edges[j].weight;
            if (!visited[v] && distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
}

int main() {
    int V = 5;
    int E = 7;
    struct Edge edges[] = {
    {0, 1, 1}, {0, 2, 4},
    {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
    {3, 2, 5}, {3, 1, 1},
    {4, 3, 3}
    };
    int distance[V];

    int source = 0;

    for (int i = 0; i < V; i++) {
        distance[i] = INF;
    }

    dijkstra(edges, V, E, source, distance);
    printDistance(distance, V);

    return 0;
}
