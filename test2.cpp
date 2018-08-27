#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string a = "abcdefg";
    string b = a.substr(2,11);
    string c = a.substr(0,3);
    cout << b << endl;
    cout << c << endl;

    return 0;
}