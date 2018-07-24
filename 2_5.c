#include<stdio.h>
#include<time.h>
#include<math.h>
//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)


int main()
{   
    int a,b,c,kase = 1;
    while(scanf("%d",&a) == 1 && a ){
        scanf("%d%d",&b,&c);
        printf("Case %d:%d.",kase,a/b);
        a = (a-a/b)*10;
        for(;c > 0 ;--c){
            if(c == 1){
                int z = a/b
            }
            printf("%d", a/b);
            a = (a-(a/b)*b)*10;
        }
    ++ kase;
    }
    return 0;
}