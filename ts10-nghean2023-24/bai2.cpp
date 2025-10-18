#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	string str;
	cin >> str;

	string tmp = "";
	vector<string>res;

	for(int i = 0 ; i < str.size(); i++) {
		if(str[i]>='0'&&str[i]<='9') {
			tmp += str[i];
		} else if(!tmp.empty()) {
			res.push_back(tmp);
			tmp = "";
		}
	}
	if (!tmp.empty()) {
		res.push_back(tmp);
		tmp = "";
	}
	stable_sort(res.begin(), res.end(), [&](string a, string b) {
		return stoll(a) < stoll(b);
		});
	for (string i : res)cout << i << ' ';
}
