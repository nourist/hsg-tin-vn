#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, m;
string s;
short dp[3003][3003][11];
int f[15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	cin >> n >> s;
	m = s.size();
	s = "_" + s;

	FOD(i, m, 1)FOD(j, m, 1)FOR(t, 0, 10) {
		if (s[i] == s[j]) {
			dp[i][j][t] = dp[i + 1][j + 1][t] + 1;
		}
		else {
			if (t)
				dp[i][j][t] = dp[i + 1][j + 1][t - 1] + 1;
		}
	}

	FOR(t, 0, 10) {
		if (t != 0)f[t] = max(f[t], f[t - 1]);

		for (int l = 1; l * 2 <= m; l++)FOR(i, 1, (m - l * 2 + 1)) {
			int j = i + l;
			if (dp[i][j][t] >= l)
				f[t] = max(f[t], l);
		}
	}

	while (n--) {
		int k;
		cin >> k;

		cout << f[k] << endl;
	}
}
