#include <stdio.h>
//factorial_iterative 3529 5967 5550 3056 4903 = 4601
//factorial 4110 5054 5751 4326 6088 = 5065.8

int pascals(int row,int col){
    if(row==col||col==0){
        return 1;
    }
    else{
        return pascals(row-1,col-1)+ pascals(row-1,col);
    }



}


int main()
{
    int row ,col;
    int pascal[100][100];
    for(row=0;row<=6;row++){
        for(col=0;col<=row;col++){
            //if(row==col||col==0){
                //pascal[row][col]=1;
            //}
            //else
                //pascal[row][col]=pascal[row-1][col-1]+pascal[row-1][col];
            //printf("%d ",pascal[row][col]);
            printf("%d ",pascals(row,col));
        }
        printf("\n");
    }

   return (0);
}
