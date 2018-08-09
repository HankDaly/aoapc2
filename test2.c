// copyright [2018] <mituh>
// 分数化小数(decimal) - 数组可进位版
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>

using namespace std;
#define MAXN 100 


int main(){
    map<vector<int>,int> aaa;
    vector<int> qqq = {1,2,3,4};
    aaa[qqq] = 1;
    cout << aaa[qqq] << endl;
    return 0;
}