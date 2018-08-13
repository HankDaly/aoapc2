#include<iostream>
#include<algorithm>
#include<time.h>
#include<vector>
#include<string.h>
using namespace std;
#define MAXN 100020
bool flag[MAXN];


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    long maxn,cnt = 0;
    for(long i = 0;i<MAXN;i++){flag[i] = 1;}
    cin >> maxn;
	flag[0]=0;            //0不是素数
	flag[1]=0;            //1不是素数
	for(long i = 2;i*i<=maxn;++i)
	{  
        /*当i为素数时，i的所有倍数都不是素数*/
		if(flag[i])
		{
			for(long j = i*i;j<=maxn;j+=i)
			{
				flag[j]=false;
			}
		}
	}
    for(long i = 0;i<maxn;i++){
        if(flag[i]){cnt++;}
    }
    cout << cnt << endl;
    cout << "Time used = " << (double)clock()/CLOCKS_PER_SEC << endl; //记时
    return 0;
} 