#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>

using namespace std;
const int maxn = 10000+10;
map<string,int> idlist;  //idlist储存所有出现过的字符串，并且赋予每个字符串唯一的id
int ch[maxn][maxn]; //ch储存本次所有字符的id

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b;
    while(cin >> a >> b){
        memset(ch,0,sizeof(ch));
        string li;
        getline(cin,li); //去换行符
        idlist.clear();
        int char_id = 0; //char_id 代表字符串的编号
        for(int i = 0;i<a;i++){
            string line,line_1;
            line.clear();
            line_1.clear();
            getline(cin,line);
            int ka = 0;
            for(auto z : line){
                if(z == ','){
                    if(idlist.count(line_1)){ch[i][ka] = idlist[line_1];ka++;}
                    else{ch[i][ka] = char_id;ka++;idlist[line_1] = char_id++;}
                    line_1.clear();
                }
                else{line_1 += z;}
            }
            if(idlist.count(line_1)){ch[i][ka] = idlist[line_1];}
            else{ch[i][ka] = char_id;idlist[line_1] = char_id++;}
        }
        //储存完毕
        int ok = 0;//ok用来标记退出
        if(a<2 || b<2){cout<< "YES" << endl;continue;}
        else{
            for(int i = 0;i<(b-1);i++){
                if(ok == 1){break;}
                for(int z = i+1;z<b;z++){
                    map<vector<int>,int> right;
                    right.clear();
                    if(ok == 1){break;}
                    for(int row = 0;row<a;row++){
                        vector<int> li = {ch[row][z],ch[row][i]};
                        if(right.count(li)){cout<< "NO" << "\n" << right[li]+1 << " "<< row+1 << "\n" << i+1 <<" "<< z+1 <<endl;ok = 1;}
                        else{right[li] = row;}
                        if(ok == 1){break;}
                    }
                }
            }
        }
        if(ok == 0){cout<< "YES" << endl;}
    }
    return 0;
}


