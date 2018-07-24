#include<stdio.h>
#include<time.h>
#include<math.h>
//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)


int main()
{
    int a ,b,kase = 1;
    double c = 0;
    while(scanf("%d",&a) == 1 && a){
        scanf("%d",&b);
        if(a<1000){
            for(;a<=b;++a){
                c += 1.0/(a*a);
            }
            if(c < 0.00001){
                c = 0.00001;
            }
            printf("Case %d:%.5lf\n",kase,c);
        }
        else
            printf("Case %d:0.00001\n",kase);
        c = 0;
        ++kase;
    }
    return 0;
}