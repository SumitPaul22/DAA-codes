#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, w, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int v[n], wt[n];
    printf("Enter the weight of knapsack: ");
    scanf("%d", &w);

    for (i = 0; i < n; i++) {
        printf("Enter the weight and value: ");
        scanf("%d %d", &wt[i], &v[i]);
    }

    int p[w + 1];
    for (i = 0; i <= w; i++)
        p[i] = 0;

    for (i = 0; i < n; i++) {
        for (j = w; j >= wt[i]; j--)
            p[j] = max(p[j], p[j - wt[i]] + v[i]);
    }

    printf("Maximum value: %d\n", p[w]);

    printf("Chosen weights and values:\n");
    j = w;
    for (i = n - 1; i >= 0; i--) {
        if (p[j] != p[j - wt[i]] + v[i]) continue;
        printf("  - Weight: %d, Value: %d\n", wt[i], v[i]);
        j -= wt[i];
    }

    return 0;
}
