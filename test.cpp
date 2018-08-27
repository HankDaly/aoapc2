#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
string ch_h[13] = {"###","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
string ch_l[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    getchar();
    for(int ii = 0;ii<N;ii++){
        string A; getline(cin,A);
        if(isdigit(A[0])){
            int temp = stoi(A);
            int high = temp/13,lower = temp%13;
            if(high == 0){cout << ch_l[lower] << endl;}
            else{
                cout << ch_h[high];
                if(lower != 0){
                    cout << " " << ch_l[lower];
                }
                cout << endl;
            }
        }
        else{
            //cout << "Aa" << A << endl;
            int A_len = A.size();
            int sum = 0;
            if(A_len>4){
                int a = A_len - 3;
                string high = A.substr(0,3),lower = A.substr(a,3);
                for(int i = 0;i<13;i++){
                    if(ch_h[i] == high){sum += i*13;break;}
                }
                for(int i = 0;i<13;i++){
                    if(ch_l[i] == lower){sum += i;break;}
                }
            }
            else{
                for(int i = 0;i<13;i++){
                    if(ch_l[i] == A){sum = i;break;}
                    else if(ch_h[i] == A){sum = i*13;break;}
                }
            }
            cout << sum << endl;
        } 
    }
    return 0;
}
