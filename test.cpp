#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string simple,A,B; cin >> simple >> A >> B;
    int A_len = A.size(),B_len = B.size(),simple_len = simple.size();
    B.insert(B.begin(),simple_len-B_len+1,'0');
    A.insert(A.begin(),simple_len-A_len+1,'0');
    A_len = A.size(); B_len = B.size();
    string sum; int go_temp = 0;
    int z = simple_len - 1;
    for(int i = B_len -1;i>=0;i--){
        int sub,mu,temp;
        sub = (A[i]-'0')+(B[i]-'0')+go_temp;
        mu = (simple[z]-'0');
        if(mu == 0){temp = (sub==0)?0:sub%10;go_temp = sub/10;}
        else{
            temp = (sub==0)?0:sub%mu;
            go_temp = sub/mu;
        }
        sum += to_string(temp);
        z--;
    }
    reverse(sum.begin(),sum.end());
    int flag = -1;
    for(int i = 0;i<sum.size();i++){
        if(sum[i] != '0'){flag = i;break;}
    }
    int len = sum.size();
    if(flag == -1){cout << 0;}
    else{cout << sum.substr(flag,len-flag);}
    return 0;
}