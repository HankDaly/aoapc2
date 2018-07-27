#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

#define maxn 100



char ch[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ*";
int a[maxn][maxn]; //a数组储存字符
int b[maxn][maxn]; //b数组储存起始格

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int kase = 0;
    for(;;){
        int y_ch,x_ch,s,y,x;
        int star = 0; //star用来起始格计数
        y_ch = getchar();
        if(y_ch == '0'){break;} //如果y是0则退出
        y = y_ch - '0';
        for(;(x_ch = getchar()) == ' ';){};
        x = x_ch - '0';
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        //开始储存字符
        for(int i = 0;i<y;++i){
            getchar(); //去掉换行符
            for(int z = 0;z<x;++z){
                s = getchar();
                if(s == '*'){a[i][z] = 26;}
                else{a[i][z] = s-'A';}
            }
        }
        getchar();
        //储存完毕
        //开始判断起始格
        for(int i = 0;i<y;++i){
            for(int z = 0;z<x;++z){
                if(a[i][z] == 26){b[i][z] = 1000;}//首先判断是否是*,是*就标记为1000
                else if(z-1<0 || a[i][z-1]==26 || i-1<0 || a[i-1][z] == 26){b[i][z] = ++star;}//其次判断是否为起始格，是的话打上1/2/3/4....
                else{b[i][z] = 0;}//最后就属于一般格子，以0标记
            }
        }
        //起始格判断完成
        //开始打印，先横后竖
        if(kase == 0){printf("puzzle #%d:\n",++kase);}
        else{printf("\npuzzle #%d:\n",++kase);}
        printf("Across\n");
        for(int i = 0;i<y;++i){
            for(int z = 0;z<x;++z){
                if(b[i][z] == 1000 || b[i][z] == 0){continue;} //如果是一般格或者*,寻找下一个
                else{
                    printf("%3d.%c",b[i][z],ch[a[i][z]]);
                    for(;;){
                        if(z+1>=x || b[i][z+1] == 1000){printf("\n");break;}//如果下右边一个格子超出或者是*，则退出循环
                        else{printf("%c",ch[a[i][++z]]);} //如果可以，则打印右边的字符，并使z加一
                    }
                }
            }
        }
        //横向打印完毕
        //打印竖向
        printf("Down\n");
        for(int i = 0;i<y;++i){
            for(int z = 0;z<x;++z){
                if(b[i][z] == 1000 || b[i][z] == 0){continue;}
                else{
                    printf("%3d.%c",b[i][z],ch[a[i][z]]);
                    int k = 1;
                    for(;;){
                        if(i+k>=y || b[i+k][z] == 1000){printf("\n");break;}
                        else{printf("%c",ch[a[i+k][z]]);b[i+k][z] = 0;k++;}
                    }
                }
        
            }
        }
    }
    return 0;
}


   

