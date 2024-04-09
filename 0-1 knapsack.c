#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, w, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int v[n], wt[n];

    printf("Enter the weight of knapsack: ");
    scanf("%d", &w);

    for(i = 0; i < n; i++) {
        printf("Enter the weight and value: ");
        scanf("%d %d", &wt[i],&v[i]);
    }

    int p[w+1]; // Declaring profit array
    for(i = 0; i <= w; i++)
        p[i] = 0;

    for(i = 0; i < n; i++) {
        for(j = w; j >= wt[i]; j--) {
            if(p[j - wt[i]] + v[i] > p[j]) {
                p[j] = p[j - wt[i]] + v[i];
            }
        }
    }

    printf("Maximum value: %d\n", p[w]);
    return 0;
}
