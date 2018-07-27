#include<stdio.h>
#include<time.h>
#include<string.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

int c,d;
int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int e,f,g;
    getchar();
    for(;(c = getchar()) == ' ';){};
    printf("%c",c);
    return 0;
}