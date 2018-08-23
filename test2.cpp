#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

long ch[100005];
vector<long> ve;
int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        ch[i] = temp;
    }
    for(int i = 0;i<N;i++){
        int ok = 1;
        for(int z = i+1;z<N;z++){
            if(ch[i] > ch[z]){ok = 0;}
        }
        for(int k = i-1;k>=0;k--){
            if(ch[i] < ch[k]){ok = 0;}
        }
        if(ok == 1){ve.push_back(ch[i]);}
    }
    sort(ve.begin(),ve.end());
    int kase = 0;
    cout << ve.size() << "\n";
    for(auto a = ve.begin();a!=ve.end();a++){
        if(kase != 0){cout << " ";}
        cout << *a;
        kase = 1;
    }
    return 0;
}