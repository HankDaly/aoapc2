#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;


int main(){
#ifdef LOCAL
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
#endif
//set
    set<int> se;
    se.insert(1);
    se.insert(2);
    se.insert(1);
    for(auto i = se.begin();i!=se.end();i++){
        cout << *i;
    }
//unorder_map
    unordered_map<int,int> mp;
    mp[1] = 1; mp[2] = 3;
    if(!mp.count(3)){mp[3] = 6;}
    cout << mp[3];
//queue
    queue<int> qe;
    qe.push(1);
    qe.push(2);
    int top = qe.front();
    cout << top;
    qe.pop();
    if(!qe.empty()){cout << qe.front();}
//  vector.erase()
    vector<int> ve{1,2,3,4};
    ve.erase(ve.begin(),3);
    cout << "\n";
    for(int i = 0;i<ve.size();i++){
        cout << ve[i];
    }
// vector.insert()
    cout << "\n";
    ve.insert(ve.begin()+2,1);
    for(int i = 0;i<ve.size();i++){
        cout << ve[i];
    }
	return 0;
//  
}
