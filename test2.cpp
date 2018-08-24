#include<iostream>
#include<cstring>

using namespace std;
int ch[100005];
int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    for(int i = 0;i < N;i++){
        int temp; cin >> temp;
        if(temp > 100000){ch[100001]++;}
        else{ch[temp]++;}
    }
    int sum = 0;
    for(int i = 100001;i>=0;i--){
        if(sum >= i){cout << i;break;}
        sum += ch[i];
    }
    return 0;
}