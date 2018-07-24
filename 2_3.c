#include<stdio.h>
#include<time.h>
#include<math.h>
//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)


int main()
{
    int a,b=0;
    scanf("%d",&a);
    for(;a>=1 ;--a){
        for(int c = 0;c<b;++c)
            printf(" ");
        for(int d = 0;d<(2*a-1);++d)
            printf("#");
        printf("\n");
        ++b;
    }
    return 0;   
}