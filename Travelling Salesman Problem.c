#include <stdio.h>
#include <limits.h>

#define N 4
#define VISITED_ALL (1<<N) - 1

int dist[N][N] = {
    {0, 400, 500, 300},
    {400, 0, 300, 500},
    {500, 300, 0, 400},
    {300, 500, 400, 0}
};

int dp[16][4];
int next[16][4];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos) {
    if(mask == VISITED_ALL) {
        return dist[pos][0];
    }
    if(dp[mask][pos] != -1) {
       return dp[mask][pos];
    }

    int ans = INT_MAX;
    int cityIndex = -1;

    // Try to go to an unvisited city
    for(int city = 0; city < N; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if(newAns < ans) {
                ans = newAns;
                cityIndex = city;
            }
        }
    }

    next[mask][pos] = cityIndex;
    return dp[mask][pos] = ans;
}

void findPath(int mask, int pos) {
    if(mask == VISITED_ALL) {
        printf("A");
        return;
    }

    int nextCity = next[mask][pos];
    printf("%c-->", 'A' + nextCity);
    findPath(mask | (1 << nextCity), nextCity);
}

int main() {
    for(int i = 0; i < (1<<N); i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = -1;
            next[i][j] = -1;
        }
    }

    printf("The minimum cost is %d\n", tsp(1, 0));
    printf("The path is: A-->");
    findPath(1, 0);
    printf("\n");

    return 0;
}
