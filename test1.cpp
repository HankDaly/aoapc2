#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
  
	string one[13] = { "tret" ,"jan", "feb", "mar","apr","may", "jun", "jly","aug", "sep", "oct", "nov","dec" },
		two[13] = { "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int n, sum = 0,res;
	string m;
	cin >> n;
	getchar();    //清除缓存（之前的回车键）
	while (n--) {
		getline(cin, m);
		if (isdigit(m[0])) {        //地球->火星
			res = atoi(m.c_str());	
			if (res/13)
				cout << two[res/13];
			if (res / 13 && res % 13)
				cout << " "<< one[res % 13];
			if (!(res/13))
				cout << one[res % 13];
			cout << endl;
		}
		else {                    //火星->地球
			for (int i = 0; i < 13; i++) {
				if (m.substr(m.length() - 3,m.length()) == one[i]) {
					sum += i;
					break;
				}			
				else if (m.substr(m.length() - 3, m.length()) == two[i]) {
					sum += (i*13);
					break;
				}
			}
			if (m.length() > 4) {
				for (int i = 0; i < 13; i++) {
					if (m.substr(0, 3) == two[i]) {
						sum += i * 13;
						break;
					}
				}
			}
			cout << sum << endl;
			sum = 0;
		}
	}
	return 0;
}