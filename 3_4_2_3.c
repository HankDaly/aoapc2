
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

#define maxn 10
//用数组，求哪两个数最接近
int main()
{
    int i[maxn];
    int a,b = 0;
    memset(i,0,sizeof(i));
    for(;scanf("%d",&a) == 1;b++){i[b] = a;}
    int min = abs(i[0] - i[1]);
    int c = i[0],d = i[1];
    for(int q = 0;q<b;q++){
        for(int z = q+1;z<b;z++){
            if(abs(i[q]-i[z])<min){c=i[q],d=i[z];}
        }
    }
    printf("%d %d",c,d);
    return 0;
}