#include <stdio.h>

int tsp[10][10] = {
    {0, 400, 500, 300},
    {400, 0, 300, 500},
    {500, 300, 0, 400},
    {300, 500, 400, 0}
};

int visited[10], n, cost = 0;

void travellingsalesman(int c) {
    int k, adj_vertex = 999;
    int min = 999;

    visited[c] = 1;
    printf("%d ", c + 1);

    for (k = 0; k < n; k++) {
        if (tsp[c][k] != 0 && !visited[k]) {
            if (tsp[c][k] < min) {
                min = tsp[c][k];
            }
            adj_vertex = k;
        }
    }

    if (min != 999) {
        cost += min;
    }

    if (adj_vertex == 999) {
        adj_vertex = 0;
        printf("%d", adj_vertex + 1);
        cost += tsp[c][adj_vertex];
        return;
    }

    travellingsalesman(adj_vertex);
}

int main() {
    int i;
    n = 5;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Shortest Path: ");
    travellingsalesman(0);
    printf("\nMinimum Cost: %d\n", cost);
    return 0;
}
