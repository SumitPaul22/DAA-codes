#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int parent[MAX], mincost = 0;

int cost[MAX][MAX] = {
    {INF, 2, INF, 6, INF},
    {2, INF, 3, 8, 5},
    {INF, 3, INF, INF, 7},
    {6, 8, INF, INF, 9},
    {INF, 5, 7, 9, INF}
};

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = 0;
    }
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a, b, u, v, n = 5, ne = 1, min;

    initialize(n);
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n) {
        for (i = 0, min = INF; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("Edge %d:(%d %d) cost:%d\n", ne++, a + 1, b + 1, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INF;
    }
    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
