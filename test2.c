#include<iostream>
#include<algorithm>
#include<time.h>
#include<vector>
#include<string.h>
#include<cstdio>
/*
题目：
1012 数字分类 (20)（20 分）
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：

30 11 2 9.7 9
输入样例2：

8 1 2 4 5 6 7 9 16
输出样例2：

N 11 2 N 9
*/

/*
总结问题:
这题有个边界条件就是
A1中要求的是能被5整除的数字中有偶数,没有偶数就算你有也得输入N
另外的教训就是,应该把所求的值与判断是否有元素分开,每个判断单独的一个变量,不要混在一起
*/

using namespace std;

#define MAXN 100020

vector<int> ve_1;
vector<int> ve_2;
vector<int> ve_3;
vector<int> ve_4;
vector<int> ve_5;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b; //a储存所有数的统计
    cin >> a;
    for(int i = 0;i<a;i++){
        cin >> b;
        if(b%5==0){ve_1.push_back(b);}
        else if(b%5==1){ve_2.push_back(b);}
        else if(b%5==2){ve_3.push_back(b);}
        else if(b%5==3){ve_4.push_back(b);}
        else{ve_5.push_back(b);}
    }

    int sum = 0; //储存所有的答案
    for(auto i = ve_1.begin();i!=ve_1.end();i++){
        if((*i)%2 == 0){sum += *i;}
    }
    if(!sum){cout << "N";}
    else{cout << sum;}

    int tem = 1;
    sum = 0;
    for(auto i = ve_2.begin();i!=ve_2.end();i++){
        if(tem%2 == 1){sum+=(*i);tem++;}
        else{sum-=(*i);tem++;} 
    }
    if(!ve_2.size()){cout << " N";}
    else{cout << " " << sum;}
    sum = 0;
    for(auto i = ve_3.begin();i!=ve_3.end();i++){
        sum++;
    }
    if(sum == 0){cout << " N";}
    else{cout << " " << sum;}
    sum = 0;
    for(auto i = ve_4.begin();i!=ve_4.end();i++){
        sum += *i;
    }
    double dd = ve_4.size();
    if(sum == 0){cout << " N";}
    else{printf(" %.1f",sum/dd);}
    sum = 0;
    for(auto i = ve_5.begin();i!=ve_5.end();i++){
        if(*i>sum){sum = *i;}
    }
    if(sum == 0){cout << " N";}
    else{cout << " " << sum;}
    return 0;
}


