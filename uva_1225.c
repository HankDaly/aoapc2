
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

#define maxn 1000000

int main()
{ 
    int a;
    scanf("%d",&a);
    for(int z = 0;z<a;z++){
        int number[10];//储存1....9的计数
        memset(number,0,sizeof(number));
        char cha_1[maxn];//储存字符
        char cha_2[maxn] = "";
        int b;
        scanf("%d",&b);
        for(int i = 1;i<=b;i++){sprintf(cha_1,"%d",i);strcat(cha_2,cha_1);}
        for(int i = 0;i<strlen(cha_2);i++){number[cha_2[i]-'0']++;}
        for(int i = 0;i<9;i++){printf("%d ",number[i]);}
        printf("%d\n",number[9]);
    }

    return 0;
}