#include <stdio.h>

int n = 5;
int ary[10][10] = {
    {0, 10, 15, 20, 25},
    {10, 0, 35, 25, 30},
    {15, 35, 0, 30, 5},  
    {20, 25, 30, 0, 20}, 
    {25, 30, 5, 20, 0}  
}, completed[10], cost = 0;

int least(int c) {
    int i, nc = 999;
    int min = 999, kmin;

    for (i = 0; i < n; i++) {
        if ((ary[c][i] != 0) && (completed[i] == 0)) {
            if (ary[c][i] < min) {
                min = ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
        }
    }

    if (min != 999)
        cost += kmin;

    return nc;
}

void mincost(int city) {
    int i, ncity;

    completed[city] = 1;

    printf("%d--->", city + 1);
    ncity = least(city);

    if (ncity == 999) {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += ary[city][ncity];

        return;
    }

    mincost(ncity);
}

int main() {
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    printf("\n\nThe Path is:\n");
    mincost(0);

    printf("\n\nMinimum cost is %d\n", cost);

    return 0;
}
