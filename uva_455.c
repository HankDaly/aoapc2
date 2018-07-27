
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

#define maxn 80+5

int main()
{  
    int s;
    scanf("%d",&s);
    while(s--){
        char ch[maxn];
        scanf("%s",ch);
        int len,nu = 0;
        len = strlen(ch); //len代表字符串的长度
        for(int i = 1;i<=len;i++){
            if(len%i == 0){
                nu = 1;
                for(int t = 0;t+i<len;t++){
                    if(ch[t+i] != ch[(t+i)%i]){nu = 0;break;}
                }
            }
            if(nu == 1 && s != 0){printf("%d\n\n",i);break;}
            if(nu == 1 && s == 0){printf("%d\n",i);break;}
        }
    }
    return 0;
}