#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    return (a>b)? a:b;
}

int main(){
    int n,w,i,j;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int wt[n],v[n];
    printf("Enter the weight of the knapsack: ");
    scanf("%d",&w);
    for (i=0;i<n;i++){
        printf("Enter the weight and profit: ");
        scanf("%d %d",&wt[i],&v[i]);
    }
    int p[w+1];
    for (i=0;i<w;i++){
        p[i]=0;
    }
    for (i=0;i<n;i++){
        for(j=w;j>=wt[i];j--){
            p[j]=max(p[j],p[j-wt[i]]+v[i]);
        }
    }
    printf("Chosen Weights and Profit are: \n");
    j=w;
    for(i=n-1;i>=0;i--){
        if(p[j]!=p[j-wt[i]]+v[i]) continue;
            printf(" - Weight: %d\tProfit:%d\n",wt[i],v[i]);
        j-=wt[i];
    }
    printf("Maximum Profit: %d",p[w]);
    return 0;
}
