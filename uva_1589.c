#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

//定义帅(G)的函数
//帅的规则是，如果与将在同一x上，如果其他几个内没有挡住，就算击杀 
//函数需要的值分别是x(将的x坐标),y(将的y坐标),cunt(当前所在数组的行数),a(总行数),ch[5][5](储存位置的二维数组),int* z(储存life地址的指针)
void g_funtion(int x,int y,int cunt,int a,int ch[10][5],int* z){
    int g_y = ch[cunt][0];
    int g_x = ch[cunt][1];
    int ok = 0; //判断标志,1表示能击杀
    if(g_x == x){
        ok = 1;
        for(int i = 0;i<a;i++){
            if(i == cunt){continue;}
            else if(ch[i][1] == x && ch[i][0] < g_y && ch[i][0] > y){ok = 0;break;}
            else{continue;}
        }
    }
    if(ok == 1){*z = 1;} //如果能杀，将life置1。
}

//定义车(R)的函数
//车的规则与帅类似，不过帅没有与将y相同的机会，而车有
void r_funtion(int x,int y,int cunt,int a,int ch[10][5],int* z){
    int r_y = ch[cunt][0];
    int r_x = ch[cunt][1];
    int ok = 0;
    if(r_x == x){
        ok = 1;
        if(r_y>y){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][1] == x && ch[i][0] < r_y && ch[i][0] > y){ok = 0;break;}
                else{continue;}
            }
        }
        if(r_y<y){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][1] == x && ch[i][0] > r_y && ch[i][0] < y){ok = 0;break;}
                else{continue;}
            }
        }
    }
    if(r_y == y){
        ok = 1;
        if(r_x>x){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][0] == y && ch[i][1] < r_x && ch[i][1] > x){ok = 0;break;}
                else{continue;}
            }
        }
        if(r_x<x){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][0] == y && ch[i][1] > r_x && ch[i][1] < x){ok = 0;break;}
                else{continue;}
            }
        }
    }
    if(ok == 1){*z = 1;}
}

//定义函数炮(C)的规则
//炮的前期和车类似，但是炮能击杀的条件是中间有且只有一个遮挡
void c_funtion(int x,int y,int cunt,int a,int ch[10][5],int* z){
    int c_y = ch[cunt][0];
    int c_x = ch[cunt][1];
    int ok = 0;
    if(c_x == x){
        if(c_y>y){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][1] == x && ch[i][0] < c_y && ch[i][0] >y){ok++;}
                else{continue;}
            }
        }
        if(c_y<y){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][1] == x && ch[i][0] > c_y && ch[i][0] < y){ok++;}
                else{continue;}
            }
        }
    }
    if(c_y == y){
        if(c_x>x){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][0] == y && ch[i][1] < c_x && ch[i][1] > x){ok++;}
                else{continue;}
            }
        }
        if(c_x<x){
            for(int i = 0;i<a;i++){
                if(i == cunt){continue;}
                else if(ch[i][0] == y && ch[i][1] > c_x && ch[i][1] < x){ok++;}
                else{continue;}
            }
        }
    }
    if(ok == 1){*z = 1;}
}
//定义马(H)的函数
//马的规则和别的不同，判断是否将住，然后判断是否有棋子挡住马
void h_funtion(int x,int y,int cunt,int a,int ch[10][5],int* z){
    int h_y = ch[cunt][0];
    int h_x = ch[cunt][1];
    int ok = 0;
    if(abs(h_y-y) == 2 && abs(h_x-x) == 1){
        ok = 1;
        for(int i = 0;i<a;i++){
            if(i == cunt){continue;}
            else if(ch[i][1] == h_x && ch[i][0] == (h_y+y)/2){ok = 0;break;}
            else{continue;}
        }
    }
    if(abs(h_y-y) == 1 && abs(h_x-x) == 2){
        ok = 1;
        for(int i = 0;i<a;i++){
            if(i == cunt){continue;}
            else if(ch[i][0] == h_y && ch[i][1] == (h_x+x)/2){ok = 0;break;}
            else{continue;}
        }
    }
    if(ok == 1){*z = 1;}
}

int ch[10][5]; //ch一维用来储存棋盘上的车(R),马(H),炮(C),二维用来储存每个棋子的位置(0-y)(1-x)

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b,c;//abc分别用来贮存每局第一行的三个数字

    while((scanf("%d%d%d",&a,&b,&c)) == 3 && a != 0){
        memset(ch,0,sizeof(ch));
        //储存其他棋子的位置
        for(int i = 0;i<a;i++){
            int q,p;
            char piece[5];
            scanf("%s%d%d",piece,&q,&p);
            ch[i][0] = q;
            ch[i][1] = p;
            ch[i][2] = piece[0] - 'A';
        }
        //根据将的上下左右最多四次循环
        for(int i = 0;i<4;i++){
            int coll = 0; //0表示无碰撞
            int life = 1; //life 是存活标志,0代表存活,1代表死亡
            int x = 0,y = 0; //x,y 用来储存移动后的将位置
            if(i == 0){x = c;y = b-1;} //0上，1下，2左，3右
            else if(i == 1){x = c;y = b+1;}
            else if(i == 2){x = c - 1;y = b;}
            else{x = c + 1;y = b;}
            for(int ki = 0;ki<a;ki++){
                if(ch[ki][0] == y && ch[ki][1] == x){coll = 1;}
            }
            //判断这次的将是否越界
            if(x>=4 && x<=6 && y>=1 && y<=3 && coll == 0){
                life = 0;
                //如果没有越界而且无碰撞，则判断将是否能够存活
                for(int cunt = 0;cunt<a;cunt++){
                    //各个棋子用各自的方法,如果能击杀，那么将life置为1
                    if(ch[cunt][2] == 'G'-'A'){g_funtion(x,y,cunt,a,ch,&life);}
                    else if(ch[cunt][2] == 'R'-'A'){r_funtion(x,y,cunt,a,ch,&life);}
                    else if(ch[cunt][2] == 'H'-'A'){h_funtion(x,y,cunt,a,ch,&life);}
                    else if(ch[cunt][2] == 'C'-'A'){c_funtion(x,y,cunt,a,ch,&life);}
                    else{printf("count = %d nothing\n",cunt);}
                }
            }
            if(life == 0){printf("No\n");break;}
            if(life == 1 && i == 3){printf("Yes\n");}
        }
    }

    return 0;
}