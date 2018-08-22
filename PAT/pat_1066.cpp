/*
1066 图像过滤（15 分）
图像过滤是把图像中不重要的像素都染成背景色，使得重要部分被凸显出来。现给定一幅黑白图像，要求你将灰度值位于某指定区间内的所有像素颜色都用一种指定的颜色替换。

输入格式：
输入在第一行给出一幅图像的分辨率，即两个正整数 M 和 N（0<M,N≤500），另外是待过滤的灰度值区间端点 A 和 B（0≤A<B≤255）、以及指定的替换灰度值。随后 M 行，每行给出 N 个像素点的灰度值，其间以空格分隔。所有灰度值都在 [0, 255] 区间内。

输出格式：
输出按要求过滤后的图像。即输出 M 行，每行 N 个像素灰度值，每个灰度值占 3 位（例如黑色要显示为 000），其间以一个空格分隔。行首尾不得有多余空格。

输入样例：
3 5 100 150 0
3 189 254 101 119
150 233 151 99 100
88 123 149 0 255
输出样例：
003 189 254 000 000
000 233 151 099 000
088 000 000 000 255
*/
/*
总结；
错误出在两处:
1.写伪代码的时候不要用数字带入，容易写错
2.运行超时先看一下输入的大小，这道题M是>0,但是没有上限，所以得注意换成scanf读入,别的判断其实影响很小。
*/


#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;

int ch[300];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int M,N,A,B,grade; cin >> M >> N >> A >> B >> grade;
    memset(ch,0,sizeof(ch));
    for(int i = A;i<=B;i++){
        ch[i] = 1;
    }

    for(int i = 0;i<M;i++){
        for(int z = 0;z<N;z++){
            int now_n ; scanf("%d",&now_n);
            if(ch[now_n] == 1){
                if(z==0){printf("%03d",grade);}
                else{printf(" %03d",grade);}
            }
            else{
                if(z==0){printf("%03d",now_n);}
                else{printf(" %03d",now_n);}
            }
        }
        if(i+1 != M){printf("\n");}
    }
    return 0;
}   

    
