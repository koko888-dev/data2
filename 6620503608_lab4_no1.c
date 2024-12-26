#include <stdio.h>

typedef struct {
    int start;
    int finish;
    int num;
} Activity;

//buble
void sort(Activity arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].finish > arr[j + 1].finish) {
                Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void GreedyActivitySelect(Activity arr[], int n) {

    sort(arr, n);


    printf("Activities are selected: %d ", arr[0].num);
    //jมีไว้เก็บ index ตัวก่อนหน้า เพื่อมาเทียบกับตัวเริ่มตัวต่อไป
    int j = 0;


    for (int i = 1; i < n; i++) {
        if (arr[i].start >= arr[j].finish) {

            printf("%d ", arr[i].num);
            j = i;
        }
    }

}


int main() {
    int n;


    printf("Input number of Activity = ");
    scanf("%d", &n);


    Activity activities[n];


    for (int i = 0; i < n; i++) {
        activities[i].num = i + 1;
        printf("Input Enter S and F of Activity %d = ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }


    GreedyActivitySelect(activities, n);

    return 0;
}
