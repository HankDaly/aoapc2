#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>

using namespace std;
//构造
struct Binstree{
    Binstree* Left;
    Binstree* Right;
    int data;
};

int leave = 0;
//主要函数
void get_leave(Binstree* T){
    vector<Binstree*> ve;
    vector<int> ve_le;
    int cnt = 0;
    while(ve.size()!=0 || T != NULL){
        while(T != NULL){
            cnt++;
            ve.push_back(T);
            ve_le.push_back(cnt);
            T = T->Left;
        }
        if(cnt > leave){leave = cnt;}
        T = ve[ve.size()-1]->Right;
        cnt = ve_le[ve_le.size()-1];
        ve.pop_back();
        ve_le.pop_back();
    }
}
//测试
Binstree* inert(Binstree* T,int value){
    if(T == NULL){
        T = new Binstree;
        T->data = value;
        T->Left = NULL; T->Right = NULL; //记得为左右都设为NULL
    }
    else{
        if(value >= T->data){T->Right = inert(T->Right,value);}
        else if(value < T->data){T->Left = inert(T->Left,value);}
    }
    return T;
}

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    Binstree* T = new Binstree; //如果T有数据 要声明空间; 没有T = NULL;
    T->data = 1;
    T->Left = NULL;
    T->Right = NULL;
    for(int i = 0;i<3;i++){
        T = inert(T,i);
    }
    T = inert(T,-1);
    T = inert(T,0);
    get_leave(T);
    cout << leave;
}