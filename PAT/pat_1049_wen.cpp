#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>

using namespace std;
double ch[100005];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    int N; cin >> N;
    double sum = 0.0;
    for(int i = 1;i<=N;i++){
        cin >> ch[i];
        sum += (N-i+1)*ch[i]*i;
    }
    printf("%.2f\n",sum);
    return 0;
}
