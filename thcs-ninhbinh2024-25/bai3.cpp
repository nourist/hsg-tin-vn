#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

vector<int>split(string str) {
	vector<int>res;
	string tmp = "";
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i]))tmp += str[i];
		else if (!tmp.empty())res.push_back(stoi(tmp)), tmp = "";
	}
	if (!tmp.empty())res.push_back(stoi(tmp));
	return res;
}

int p[(int)1e6 + 6];
void sieve() {
	for (int i = 1; i <= 1e6; i++)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i] == i) {
			for (int j = i * i; j <= 1e6; j += i) {
				p[j] = min(p[j], i);
			}
		}
	}
}

int f[(int)1e6 + 6], cnt =0;
void add(int x) {
	unordered_set<int>s;
	while (x != 1) {
		s.insert(p[x]);
		x /= p[x];
	}

	for (int i : s) {
		if (f[i] == 1)cnt++;
		f[i]++;
	}
}

void remove(int x) {
	unordered_set<int>s;
	while (x != 1) {
		s.insert(p[x]);
		x /= p[x];
	}

	for (int i : s) {
		if (f[i] == 2)cnt--;
		f[i]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	sieve();

	string str;
	cin >> str;

	vector<int>a = split(str);
	int l = 0, r = 0, res = 0;
	while (r < a.size()) {
		add(a[r]);
		while (cnt > 0) {
			remove(a[l++]);
		}
		res = max(res, r - l + 1);
		r++;
	}
	cout << res;
}
