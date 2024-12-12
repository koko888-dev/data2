#include <stdio.h>
#include <sys/time.h>
factorial_iterative 3529 5967 5550 3056 4903 = 5693.8
factorial 4110 5054 5751 4326 6088 = 5065.8
long double factorial(int n)
{

   if (n == 1)
      return n;
   else
      return n * factorial(n - 1);
}
long double factorial_iterative(int n)
{

   long double result = 1;
   for (int i = n; i >= 1; i--)
   {
      result *= i;
   }

   return result;
}



int main()
{

    struct timeval stop, start;
    gettimeofday(&start, NULL);

    for(int i=0;i<1000;i++){
        printf("%Lf ",factorial_iterative(60));
    }

    //printf("%lld",factorial_iterative(60));

    gettimeofday(&stop, NULL);
    printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 +stop.tv_usec - start.tv_usec);


   return (0);
}
