#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int pi[60];
int nxt[60][2];
int dp[61][60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PLASMID.inp", "r")) {
		freopen("PLASMID.inp", "r", stdin);
		freopen("PLASMID.out", "w", stdout);
	}

	int n;
	string s;

	cin >> n >> s;
	FOR(i, 1, s.size() - 1) {
		int j = pi[i - 1];
		while (j > 1 && s[j] != s[i])j = pi[j - 1];
		if (s[i] == s[j])j++;
		pi[i] = j;
	}

	FOR(i, 0, s.size() - 1) {
		FOR(j, 0, 1) {
			if (s[i] - '0' == j)nxt[i][j] = i + 1;
			else nxt[i][j] = i > 1 ? pi[i - 1] : 0;
		}
	}

	ll res = 0;
	FOR(st, 0, s.size() - 1) {
		memset(dp, 0, sizeof dp);
		dp[0][st] = 1;
		FOR(i, 0, n - 1) {
			FOR(j, 0, s.size() - 1) {
				FOR(k, 0, 1)
					dp[i + 1][nxt[j][k]] += dp[i][j];
			}
		}
		res += dp[n][st];
	}
	cout << res;
}
