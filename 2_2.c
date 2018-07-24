#include<stdio.h>
#include<time.h>
#include<math.h>
//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)


int main()
{
    int a,kase = 1 ;
    while(scanf("%d",&a) == 1 ){
        int b,c;
        scanf("%d%d",&b,&c);
        for(int d = 10;d <= 100;++d){
            if(d%3 == a && d%5 == b && d%7 == c){
                printf("Case %d:%d\n",kase,d);
                break;
            }
            if(d == 100){
                printf("Case %d:No answer\n",kase);
            }
        }
        ++kase;
    }
    printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;   
}