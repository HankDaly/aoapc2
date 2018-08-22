/*
1028 人口普查（20 分）
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数 N，取值在(0,10
​5
​​ ]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/
/*
总结:
这道主要用的是string的比较大小,注意的一点是当没有人合法的时候，只需要打印0就行了。
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<cctype>

using namespace std;
#define MAXN 10000005



int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif  
    string name,age;
    int N;
    cin >> N;
    int kase = 0;
    string max_brithday = "2014/09/06";
    string min_brithday = "1814/09/06"; 
    string max_name;
    string min_name;
    for(int i = 0;i<N;i++){
        string name,brithday;
        cin >> name >> brithday;
        if(brithday>="1814/09/06" && brithday <="2014/09/06"){
            kase++;
            if(brithday >= min_brithday){min_brithday = brithday;min_name = name;}
            if(brithday <= max_brithday){max_brithday = brithday;max_name = name;}
        }
        else{}
    }
    if(kase == 0){cout << kase;}
    else{
        cout << kase << " " << max_name << " " << min_name;
    }
    return 0;
}