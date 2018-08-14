#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>
#include<string.h>

using namespace std;

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b;
    int ok = 0;
    int kase = 0;
    while(cin>>a>>b){
        if(b == 0){}
        else{
            if(kase == 0){cout<< a*b << " " << b-1;}
            else{cout<< " " << a*b << " " << b-1;}
            ok = 1;
                   }
        kase++;
    }
    if(ok == 0){cout << 0 << " " << 0;}

}
    

    
