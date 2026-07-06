#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int f[(int)1e5 + 5][26];

int cost(int i, int j) {
	return min(abs(i - j), 26 - abs(i - j));
}

int solveV(vector<int>& v) {
	int res = 0;
	for (auto i : v)for (auto j : v)res = max(res, cost(i, j));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("khoangcach.inp", "r")) {
		freopen("khoangcach.inp", "r", stdin);
		freopen("khoangcach.out", "w", stdout);
	}

	string str;
	cin >> str;

	FOR(i, 1, str.size()) {
		FOR(j, 0, 25)f[i][j] += f[i - 1][j];
		f[i][str[i - 1] - 'a']++;
	}

	int q, l, r;
	cin >> q;
	while (q--) {
		cin >> l >> r;
		vector<int>v;
		FOR(i, 0, 25) {
			int cnt = f[r][i] - f[l - 1][i];
			if (cnt >= 1)v.push_back(i);
		}
		cout << solveV(v) << '\n';
	}
}
