#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

struct Edge {
    int source, destination, weight;
};

int main() {
    int V, E, i, j, u, v, w;
    printf("Enter number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter number of edges in the graph: ");
    scanf("%d", &E);
    
    struct Edge edges[E];
    
    printf("Enter the source, destination and weight of each edge:\n");
    for(i = 0; i < E; i++) {
        scanf("%d%d%d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }
    
    int distance[V];
    
    for(i = 0; i < V; i++) {
        distance[i] = INF;
    }
    
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    distance[source] = 0;
    
    // Relaxation process
    for(i = 0; i < V - 1; i++) {
        for(j = 0; j < E; j++) {
            u = edges[j].source;
            v = edges[j].destination;
            w = edges[j].weight;
            if(distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
    
    // Check for negative weight cycles
    for(i = 0; i < E; i++) {
        u = edges[i].source;
        v = edges[i].destination;
        w = edges[i].weight;
        if(distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return 0;
        }
    }
    
    printf("Vertex\tDistance from Source\n");
    for(i = 0; i < V; i++) {
        printf("%d \t %d\n", i, distance[i]);
    }
    
    return 0;
}
