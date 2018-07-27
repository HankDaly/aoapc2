
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

#define maxn 5
char ch[] =" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int a[10][10];


int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int c,q,kase =1; //Kase表示次数
    for(;;){
        int wre = 1,ok = 1,x = 0,y = 0; //wre变0则退出，ok代表本次是否有违法操作,x,y是空格坐标
        memset(a,0,sizeof(a));
        for(int i = 0;i < 5;i++){
            for(int z = 0;z < 6;z++){
                c = getchar();
                if(c == ' '){a[i][z] = 0;x = z;y = i;}
                else if(c == 'Z'){wre = 0;} 
                else if(c == '\n'){break;}
                else{a[i][z] =(c-'A'+1);} //空格是0，所以通通加一
            }
        }
        //方块内容获取完毕
        if(wre == 0){break;}//判断退出点
        //一切正常后开始移动,一直读取直到0为止
        for(;;){
            c = getchar();
            if(c == 'A' && y-1>=0){a[y][x] = a[y-1][x];a[y-1][x] = 0;y=y-1;}
            else if(c == 'B' && y+1<=4){a[y][x] = a[y+1][x];a[y+1][x] = 0;y=y+1;}
            else if(c == 'L' && x-1>=0){a[y][x] = a[y][x-1];a[y][x-1] = 0;x=x-1;}
            else if(c == 'R' && x+1<=4){a[y][x] = a[y][x+1];a[y][x+1] = 0;x=x+1;}
            else if(c == '0'){q = getchar();break;}
            else if(c == '\n'){continue;}
            else{
                ok = 0;
                for(int d;(d = getchar()) != '0';){}
                q = getchar();
                break;
            }
        }  
        //打印阶段
        if(kase == 1){printf("Puzzle #%d:\n",kase++);}
        else{printf("\nPuzzle #%d:\n",kase++);}
        //如果ok=0，则说明违法操作。ok=1,正常打印
        if(ok == 0){printf("This puzzle has no final configuration.\n");}
        else{
            for(int i = 0;i<5;i++){
                for(int z = 0;z<5;z++){
                    if(z == 4){printf("%c\n",ch[a[i][z]]);}
                    else{printf("%c ",ch[a[i][z]]);}
                }
            }
        }
    }
    return 0;
}


   

