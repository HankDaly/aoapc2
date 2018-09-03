#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct Node{
    int No;
    int score;
    int all_n;
    int true_n;
    int t_selected = 0;
    int wrong = 0;
};
bool cmp(Node a,Node b){
    if(a.wrong == b.wrong){return a.No<b.No;}
    else{return a.wrong>b.wrong;}
}
Node ch[105];
int ha[] = {1,2,4,8,16};
int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N,M; cin >> N >> M;
    for(int i = 0;i<M;i++){
        Node node; cin >> node.score >> node.all_n >> node.true_n;
        node.No = i+1;
        for(int z = 0;z<node.true_n;z++){
            string temp; cin >> temp;
            node.t_selected += ha[(temp[0]-'a')];
        }
        ch[i] = node;
    }
    //题目整理完毕
    for(int i = 0;i<N;i++){
        char a;
        int kase = 0,student_sc = 0;
        while((a = getchar()) != EOF){
            int selected = 0;
            if(a == '('){
                int number; cin >> number;
                for(int z = 0;z<number*2;z++){
                    char c; c = getchar();
                    if(c != ' '){selected += ha[c-'a'];}
                }
                if(selected^ch[kase].t_selected){ //如果不是零，代表有不一样的
                    ++ch[kase].wrong;
                }
                else{student_sc += ch[kase].score;}
                ++kase;
            }
            if(kase == M){cout << student_sc << "\n";break;}
        }
    }
    // 学生统计完
    sort(ch,ch+105,cmp);
    if(ch[0].wrong == 0){cout << "Too simple";}
    else{
        cout << ch[0].wrong;
        for(int i = 0;ch[i].wrong == ch[0].wrong;i++){
            cout <<" "<< ch[i].No;
        }
    }
    
	return 0;
}