#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string a = "abc";
    int temp = toupper(a[1]);
    cout << temp;

    return 0;
}