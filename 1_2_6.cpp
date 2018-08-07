#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>

using namespace std;
const int maxn = 100+10;

string find_min(string a){
    string c = a;
    int ka = a.size();
    for(int i = 1;i < ka;i++){
        string b = a;
        for(int z = 0;z < ka;z++){
            b[(z+i)%ka] = a[z];
        }
        if(b <= c){c = b;}
    }
    return c;
}

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string q,p,q_min,p_min;
    cin >> q >> p;
    q_min = find_min(q);
    p_min = find_min(p);
    if(q_min == p_min){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
}


