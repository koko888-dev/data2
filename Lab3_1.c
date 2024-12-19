#include<stdio.h>


void merge(int arr[],int first,int mid,int last,int rec){
    int n1 = mid-first+1;
    int n2 = last-mid;

    int L[n1],R[n2];

    int i=0,j=0;
    for(i=0;i<n1;i++){
        L[i] = arr[first+i];

    }

    for(j=0;j<n2;j++){
        R[j] = arr[mid+j+1];
    }


    i=0,j=0;
    int k=first;

    for(k=first;k<last;k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }



    printf("Rec : %d = ",rec);
    printarr(arr,8);


}

void mergesort(int arr[],int first,int last,int rec){

    if(first<last){
        int mid = (first+last)/2;

        mergesort(arr,first,mid,rec+1);
        mergesort(arr,mid+1,last,rec+1);
        merge(arr,first,mid,last,rec);

    }
}

void printarr(int arr[],int size){

        for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}

int main(){

    int arr[8]={27,5,2,7,9,3,2,10};
    int size = 8;


    printf("Given array is: ");
    printarr(arr,8);

    mergesort(arr,0,size-1,1);
    printf("Sorted array is\n");
    printarr(arr,8);



return 0;
}
