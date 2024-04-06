#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

struct Edge {
    int source, destination, weight;
};

void printDistance(int distance[], int V) {
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < V; i++) {
        if(distance[i] == INF)
            printf("%d \t %s\n", i, "INF");
        else
            printf("%d \t %d\n", i, distance[i]);
    }
}

void bellmanFord(struct Edge edges[], int V, int E, int source, int distance[]) {
    // Initialize distances from source to all other vertices as INFINITE
    for(int i = 0; i < V; i++) {
        distance[i] = INF;
    }
    distance[source] = 0;

    // Relaxation process
    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;
            if(distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for(int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int w = edges[i].weight;
        if(distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 7; // Number of edges
    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1},
        {4, 3, -3}
    };
    int distance[V];

    int source = 0; // Source vertex
    
    bellmanFord(edges, V, E, source, distance);
    printDistance(distance, V);
    
    return 0;
}
