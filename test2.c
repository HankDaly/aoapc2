#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define MAXN 10000005


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    vector<int> ve;
    ve[2] += 100;
    cout << ve[2] << endl;
}