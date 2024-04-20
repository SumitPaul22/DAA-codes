#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

void jobSequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);

    int slots[n];
    for (int i = 0; i < n; ++i)
        slots[i] = -1;

    int totalProfit = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = jobs[i].deadline - 1; j >= 0; --j) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected job sequence: ");
    for (int i = 0; i < n; ++i) {
        if (slots[i] != -1)
            printf("%d ", slots[i]);
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    struct Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30},
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
