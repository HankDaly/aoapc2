#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
using namespace std;

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    string a = "string";
    int b = a.size();
    for(int i = 0;i<b;i++){
        for(int q = i+1;q<b;q++){
            string temp_1;
            cout << temp_1 + a[i] + a[q] << endl;
        }
        for(int z = i-1;z>=0;z--){
            string temp_2;
            cout << temp_2+a[i]+a[z] << endl;
        }
    }
    return 0;
    
}