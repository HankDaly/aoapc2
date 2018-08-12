// copyright [2018] <mituh>
// 分数化小数(decimal) - 数组可进位版
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<math.h>

using namespace std;
#define MAXN 100 

vector<int> q;
void udef(vector<int>& q,int n){
    q.push_back(n);
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int n = 2;
    udef(q,n);
    cout<< q[0] << endl;
}