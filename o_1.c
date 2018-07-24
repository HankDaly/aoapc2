#include<stdio.h>
#include<time.h>
#include<math.h>
//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)


int main()
{   
    int x,n = 1;
    scanf("%d",&x);
    for(;x >= (int)(pow(2,n))-1;){
        x -= (int)(pow(2,n)-1);
        ++n;
    }
    for(int z = n;z > 0;--z){
        printf("%d",x/(int)pow(2,(z-1)));
        x = x%((int)pow(2,(z-1)));
    }
    return 0;
}