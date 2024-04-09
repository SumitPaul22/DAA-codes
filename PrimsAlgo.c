#include<stdio.h>
#include<stdlib.h>

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
    int b, u, v, n = 5, i, j, ne = 1;
    int visited[MAX] = {0}, min, mincost = 0, a;
    visited[0] = 1;
    printf("The edges of Minimum Cost Spanning Tree are\n")
    while(ne < n-1) {
        for(i = 0, min = INF; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min && visited[i] != 0 && visited[j] == 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        printf("\nEdge %d:(%d %d) cost:%d", ne++, a+1, b+1, min);
        mincost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = INF; 
    }
    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
