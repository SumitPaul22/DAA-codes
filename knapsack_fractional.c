#include<stdio.h>

int main() {
    int n, i, j;
    float v[100], wt[100], r[100], w, o, d, temp, rem, current = 0, totalval = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the weight of knapsack: ");
    scanf("%f", &w);
    
    for(i = 0; i < n; i++) {
        printf("Enter the weight and value: ");
        scanf("%f %f", &o, &d);
        wt[i] = o;
        v[i] = d;
        r[i] = v[i] / wt[i];
    }
    
    // Bubble sort the arrays based on the ratio r[]
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(r[j] < r[j + 1]) { // Sorting in descending order
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                
                temp = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp;
                
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    
    // Calculate the maximum value
    for(i = 0; i < n; i++) {
        if(current + wt[i] <= w) {
            current += wt[i];
            totalval += v[i];
        } else {
            rem = w - current;
            totalval += rem * r[i];
            break;
        }
    }
    
    printf("Maximum value: %.2f \n", totalval);
    
    return 0;
}
