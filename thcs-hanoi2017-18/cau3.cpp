#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll p11[1000];

vector<string> intFromString(string s) {
	string tmp = "";
	vector<string> res;
	for (int i = 0; i < s.size(); i++) {
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

bool subStr(string s, string t) {
	int mod = 1e9 + 7;

	int n = s.size();
	int m = t.size();
	s = "_" + s;
	t = "_" + t;

	ll hashT = 0;
	for(int i = 1; i <= m; i++) {
		hashT = (hashT*11+ t[i]-47)%mod;
	}

	vector<ll> hashS(n+1);
	hashS[0] = 0;
	for (int i = 1; i <= n; i++) {
		hashS[i] = (hashS[i - 1] * 11 + s[i] - 47) % mod;
	}

	for(int i = m; i <= n; i++) {
		int hashS1 = (hashS[i] - (hashS[i - m] * p11[m]) % mod + mod) % mod;
		if(hashS1 == hashT) {
			return true;
		}
	}
	return false;
}

vector<string>allSubStr(string s) {
	vector<string> res;
	int n = s.size();
	s = "_" + s;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			res.push_back(s.substr(i, j - i + 1));
		}
	}
	return res;
}

string maxS(string a, string b) {
	while(a.size() > 0 && a[0] == '0') {
		a.erase(a.begin());
	}
	while(b.size() > 0 && b[0] == '0') {
		b.erase(b.begin());
	}
	if (a.size() != b.size()) {
		return a.size() > b.size() ? a : b;
	}
	for(int i = 0; i < a.size(); i++) {
		if(a[i] != b[i]) {
			return a[i] > b[i] ? a : b;
		}
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	p11[0] = 1;
	for (int i = 1; i <= 999; i++) {
		p11[i] = (p11[i - 1] * 11) % ((int)1e9 + 7);
	}

	string a, b;
	cin >> a >> b;

	vector<string>v1 = intFromString(a);
	vector<string>v2 = intFromString(b);

	vector<string>v3;
	for(int i = 0; i < v2.size(); i++) {
		vector<string>v4 = allSubStr(v2[i]);
		for(int j = 0; j < v4.size(); j++) {
			v3.push_back(v4[j]);
		}
	}

	string res = "0";
	for(int i = 0; i < v1.size(); i++) {
		for(int j = 0; j < v3.size(); j++) {
			if(subStr(v1[i], v3[j])) {
				res=maxS(res, v3[j]);
			}
		}
	}
	cout << res << endl;
}
