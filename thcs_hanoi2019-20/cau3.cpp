#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e5 + 5];

vector<string>numberStrings(string s) {
	vector<string>res;
	string tmp = "";
	for(int i = 0; i < s.size(); i++) {
		if(isdigit(s[i])) {
			tmp += s[i];
		} else {
			if(tmp != "") {
				res.push_back(tmp);
				tmp = "";
			}
		}
	}
	if(tmp != "") {
		res.push_back(tmp);
	}
	return res;
}

vector<string>allSubStrings(string s, int k) {
	vector<string>res;
	for(int i = 0; i < s.size(); i++) {
		for(int j = i + 1; j <= s.size(); j++) {
			string tmp = s.substr(i, j - i);
			if(tmp.size() <= k) {
				res.push_back(tmp);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	memset(p, 1, sizeof(p));
	for(int i = 2; i * i <= (int)1e5; i++) {
		if (p[i]) {
			for (int j = i * i; j <= (int)1e5; j += i) {
				p[j] = 0;
			}
		}
	}

	string str;
	cin >> str;

	int n = str.size();

	vector<string>v1 = numberStrings(str);
	vector<string>v2;
	for (int i = 0; i < v1.size(); i++) {
		vector<string>tmp = allSubStrings(v1[i], 5);
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j].size() > 0) {
				v2.push_back(tmp[j]);
			}
		}
	}

	int res = 0;
	for(int i = 0; i < v2.size(); i++) {
		if (p[stoi(v2[i])]) {
			res=max(res, stoi(v2[i]));
		}
	}
	cout << res << endl;
}
