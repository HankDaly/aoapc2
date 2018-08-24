#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    double max = 0.00;
    for(int i = 0;i<N;i++){
        int shi,xu; cin >> shi >> xu;
        double a = sqrt(shi*shi+xu*xu);
        if(a>=max){max = a;}
    }
    printf("%.2lf",max);
    return 0;
}
