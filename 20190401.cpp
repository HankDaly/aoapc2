#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>

using namespace std;


BiNode* Search_SmallestK(BiNode* bt,int k){
    int right;
    if(bt->right == NULL){right = 0;}
    else{right = bt->right->count;}
    int now = bt->count - right;
    //判断是否是K
    if(now == k){return bt;}
    //如果当前大于k
    else if(now > k){bt->left->count = now-2;return Search_SmallestK(bt->left,k);}
    else{bt->right->count = bt->count+1;return Search_SmallestK(bt->right,k);}
}

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
}