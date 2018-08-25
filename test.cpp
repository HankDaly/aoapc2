#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
long ch[100005];
vector<long> ve;
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    long p; cin >> p;
    int max = 0;
    for(int i = 0;i<N;i++){
        long temp; cin >> temp;
        ch[temp] = 1;
        ve.push_back(temp);
    }
    for(int i = 0;i<N;i++){
        int cnt = 0;
        for(int z = ve[i];z<ve[i]*p;z++){
            if(ch[z] == 1){cnt++;}
        }
        if(cnt >= max){max = cnt;}
    }
    cout << max;
    return 0;
}
