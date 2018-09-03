#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int ch_value[100005];
int ch_last[100005];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int first_node,K,N; cin >> first_node >> N >> K;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        cin >> ch_value[temp] >> ch_last[temp];
    }
    //首先先来一遍小于0循环
    int temp_node = first_node;
    int kase = 0;
    while(temp_node != -1){
        if(ch_value[temp_node] < 0 && kase == 0){
            printf("%05d %d",temp_node,ch_value[temp_node]);
            ++kase;
        }
        else if(ch_value[temp_node] < 0 && kase > 0){
            printf(" %05d\n%05d %d",temp_node,temp_node,ch_value[temp_node]);
        }
        else{}
        temp_node = ch_last[temp_node];
    }
    //第二遍就是0-K之间
    temp_node = first_node; // temp_node重置
    while(temp_node != -1){
        if(ch_value[temp_node] >= 0 && ch_value[temp_node] <= K && kase == 0){
            printf("%05d %d",temp_node,ch_value[temp_node]);
            ++kase;
        }
        else if(ch_value[temp_node] >= 0 && ch_value[temp_node] <= K && kase == 1){
            printf(" %05d\n%05d %d",temp_node,temp_node,ch_value[temp_node]);
        }
        else{}
        temp_node = ch_last[temp_node];
    }
    //第三遍大于K
    temp_node = first_node; // temp_node重置
    while(temp_node != -1){
        if(ch_value[temp_node] > K && kase == 0){
            printf("%05d %d",temp_node,ch_value[temp_node]);
            ++kase;
        }
        else if(ch_value[temp_node] > K && kase == 1){
            printf(" %05d\n%05d %d",temp_node,temp_node,ch_value[temp_node]);
        }
        else{}
        temp_node = ch_last[temp_node];
    }
    printf(" -1");
    return 0;
}