#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX] = {
    {INF, 2, INF, 6, INF},
    {2, INF, 3, 8, 5},
    {INF, 3, INF, INF, 7},
    {6, 8, INF, INF, 9},
    {INF, 5, 7, 9, INF}
};

int main() {
    int n = 5, ne = 1;
    int visited[MAX] = {0}, mincost = 0, a, b;

    visited[0] = 1;
    printf("The edges of Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        int min = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min && visited[i] && !visited[j]) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        printf("Edge %d: (%d %d) cost: %d\n", ne++, a + 1, b + 1, min);
        mincost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost = %d\n", mincost);
    return 0;
}
