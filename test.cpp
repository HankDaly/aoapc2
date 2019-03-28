#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<unordered_map>
using namespace std;

struct Node{
	string all_id;
	string lv;
	string site;
	string data;
	string number;
	int score;
};

vector<Node> ve;
vector<Node> temp_ve;

//
bool cmp_1(Node a,Node b){
	if(a.score == b.score){return a.all_id<b.all_id;}
	else{return a.score > b.score;}
}

void deal_1(string leve){
	for(int i = 0;i<ve.size();i++){
		if(ve[i].lv[0] == leve[0]){temp_ve.push_back(ve[i]);}
	}
	sort(temp_ve.begin(),temp_ve.end(),cmp_1);
	if(temp_ve.size() == 0){cout << "NA\n";}
	else{
		for(int i = 0;i<temp_ve.size();i++){
			cout << temp_ve[i].all_id << " " << temp_ve[i].score;
			cout << "\n";
		}
	}
}
//
void deal_2(string site){
	int cnt = 0;
	int sum = 0;
	for(int i = 0;i<ve.size();i++){
		if(ve[i].site == site){cnt++; sum += ve[i].score;}
	}
	if(cnt == 0){cout << "NA\n";}
	else{cout << cnt << " " << sum <<"\n";}
}
//
bool cmp_3(Node a,Node b){
    if(a.score == b.score){return a.data < b.data;}
    else{return a.score > b.score;}
}

void deal_3(string data){
    unordered_map<string,int> mp;
    for(int i = 0;i<ve.size();i++){
        if(ve[i].data == data){
            if(!mp.count(ve[i].site)){mp[ve[i].site] = 1;}
            else{mp[ve[i].site]++;}
        }
    }
    for(auto i = mp.begin();i!=mp.end();i++){
        Node node; node.data = i->first; node.score = i->second;
        temp_ve.push_back(node);
    }
    if(temp_ve.size() == 0){cout << "NA\n";}
    else{
        sort(temp_ve.begin(),temp_ve.end(),cmp_3);
        for(int i = 0;i<temp_ve.size();i++){
            cout << temp_ve[i].data << " " << temp_ve[i].score << "\n";
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
#endif
	int N,M; cin >> N >> M;
	for(int i = 0;i<N;i++){
		string temp; cin >> temp;
		int score; cin >> score;
		Node node; node.all_id = temp; node.score = score;
		node.lv = temp[0];
		node.site = temp.substr(1,3);
		node.data = temp.substr(4,6);
		node.number = temp.substr(10,3);
		ve.push_back(node);
	}
	//储存完毕
	for(int i = 0;i<M;i++){
		temp_ve.clear();
		int number; cin >> number;
		string st; cin >> st;
		cout << "Case "<<i+1<<": "<<number<<" "<<st<<"\n";
		if(number == 1){deal_1(st);}
		else if(number == 2){deal_2(st);}
		else{deal_3(st);}
	}
	return 0;
}