#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int ch_p[100005];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A; cin >> A;
    int A_len = A.size();
    int sum = 0;
    int p_n = 0;
    for(int i = 0;i<A_len;i++){
        if(A[i] == 'P'){p_n++;ch_p[i] = p_n;}
        else{ch_p[i] = p_n;}
    }
    int t_n = 0;
    for(int i = A_len-1;i>=0;i--){
        if(A[i] == 'T'){t_n++;}
        if(A[i] == 'A'){sum = (sum+t_n*ch_p[i])%1000000007;}
    }
    cout << sum;
    return 0;
}
