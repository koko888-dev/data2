#include<stdio.h>
int main(){

    int i=0;
    long long int n0=0,n1=1,sum=0;
    for(i=0;i<50;i++){
        if(i==0) printf("%lld ",n0);
        if(i==1) printf("%lld ",n1);
        if(i>1){
        sum=n0+n1;
        n0=n1;
        n1=sum;
        printf("%lld ",sum);
        }
    }







return 0;
}
