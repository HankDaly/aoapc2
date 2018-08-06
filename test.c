#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100+10;
int A[maxn];

int main()
{  
/*#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif*/
    long long a,b;
    while(cin >> a >> b){
        cout << min(a,b) << "\n" << endl;
    }
    return 0;
}


