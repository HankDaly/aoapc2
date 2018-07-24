
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

#define maxn 80 +10

int main()
{
    double ch[maxn];
    ch[2] = 12.01;
    ch[7] = 1.008;
    ch[13] = 14.01;
    ch[14] = 16.00;

    int number;
    scanf("%d",&number);
    for(int i = 0;i < number;i++){
        char s[maxn];
        scanf("%s",s);  //读取分子式为s
        int place[maxn],dou[maxn]; //palce数组储存该分子式所有字母的位置,dou数组储存每个字母后有多少位的数字
        int t = 0;
        double summize = 0; //t记录一共有多少字母,summize记录总和
        for(int i = 0;i < strlen(s);i++){
            if(isalpha(s[i])){place[t] = i;t++;}
        }
        for(int i = 0; i < t;i++){
            if(t-i == 1){dou[i] = strlen(s) - place[t-1]-1;}
            else{dou[i] = place[i+1]-place[i]-1;}
        }
        for(int i = 0; i < t;i++){
            int doub = 0; //doub用来记录具体的数字,sub记录当前总和
            if(dou[i] == 0){doub = 1;}
            else{
                int q = 1;
                for(int x = dou[i]; x > 0;x--){
                    doub += pow(10,(x-1))*(s[place[i]+q]-'0');
                    q++;
                }
            }
            summize += doub*ch[(s[place[i]] - 'A')];
        }
        printf("%.3lf\n",summize);
    }
    
    return 0;
}