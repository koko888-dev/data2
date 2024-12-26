#include <stdio.h>
#include <stdlib.h>
//O(n)
struct activity {
    int val;
    int wt;
    double percent;
};


int compare(const void* a, const void* b) {
    double percent_a = ((struct activity*)a)->val / (double)((struct activity*)a)->wt;
    double percent_b = ((struct activity*)b)->val / (double)((struct activity*)b)->wt;


    if (percent_a < percent_b) return 1;
    else if (percent_a > percent_b) return -1;
    else return 0;
}


void greedyknapsack(struct activity arr[], int w, int n) {
    int sumwt = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n && sumwt < w; i++) {
        if (sumwt + arr[i].wt <= w) {
            arr[i].percent = 1.0;
        } else {
            arr[i].percent = (double)(w - sumwt) / arr[i].wt;
        }

        sumwt += arr[i].percent * arr[i].wt;
        totalValue += arr[i].percent * arr[i].val;

    }
    printf("The results of xi is : ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ",arr[i].percent);
    }
    printf("\n Maximum value is: %.2f",totalValue);
}

int main() {
    int n = 4;
    struct activity arr[n];

    int w;


    printf("Enter w : ");
    scanf("%d", &w);


    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].val, &arr[i].wt);
    }


    qsort(arr, n, sizeof(struct activity), compare);


    greedyknapsack(arr, w, n);




    return 0;
}
