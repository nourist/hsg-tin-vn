#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first
#define Y second 

ll dp[(int)1e6][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("adn.inp", "r")) {
		freopen("adn.inp", "r", stdin);
		freopen("adn.out", "w", stdout);
	}

	string s;
	cin >> s;

	int n = s.size();

	if (s == string(n, '?')) {
		cout << 0;
		return 0;
	}

	ll res = 1LL * n * (n - 1);

	vector<pii>v;
	for (auto i : s) {
		if (v.empty() || v.back().X != i) {
			if (v.size() > 1 && v.back().X == '?' && v[v.size() - 2].X == i) {
				int cnt = v.back().Y;
				v.pop_back();
				v.back().Y += cnt + 1;
			}
			else if (v.size() == 1 && v.back().X == '?') {
				int cnt = v.back().Y;
				v.pop_back();
				v.push_back({ i, cnt + 1 });
			}
			else v.push_back({ i, 1 });
		}
		else {
			v.back().Y++;
		}
	}

	if (v.back().X == '?') {
		int cnt = v.back().Y;
		v.pop_back();
		v.back().Y += cnt;
	}

	for (auto i : v) {
		res -= 1LL * i.Y * (i.Y - 1);
	}

	vector<int>blocks;

	FOR(i, 0, v.size() - 1) {
		if (v[i].X == '?')blocks.push_back(i);
	}

	FOR(i, 1, blocks.size()) {
		dp[i][0] = dp[i - 1][0] + 1LL * v[blocks[i - 1]].Y * v[blocks[i - 1] - 1].Y;
		if (i >= 2 && blocks[i - 1] - 2 == blocks[i - 2])dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1LL * v[blocks[i - 1]].Y * (v[blocks[i - 1] - 1].Y + v[blocks[i - 1] - 2].Y));
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + 1LL * v[blocks[i - 1]].Y * v[blocks[i - 1] + 1].Y;
	}

	cout << res / 2 - max(dp[blocks.size()][0], dp[blocks.size()][1]);
}

/*
n = |s|

res = n*(n-1)/2 - ki * (ki-1)/2

*/