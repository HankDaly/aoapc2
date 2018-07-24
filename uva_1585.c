
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

#define maxn 80 +10

int main()
{ 
    int number,a = 0;
    scanf("%d",&number);
    while(a < number){
        char s[maxn];
        scanf("%s",s);
        int b = 0,c =0;
        for(int z = 0;z < strlen(s);z++){
            if(s[z] == 'O'){++b;}
            if(s[z] == 'X'){b = 0;}
            c += b;
        }
        ++a;
        printf("%d\n",c);
    }

    return 0;
}