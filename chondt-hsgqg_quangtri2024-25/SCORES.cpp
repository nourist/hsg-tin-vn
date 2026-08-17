#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll dp[5005][5005];
const ll mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("SCORES.inp", "r")) {
		freopen("SCORES.inp", "r", stdin);
		freopen("SCORES.out", "w", stdout);
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;

		memset(dp, 0, sizeof dp);
		dp[0][1] = 1;
		FOR(i, 1, n)FOR(j, 1, n) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] %= mod;
		}
		cout << dp[n][n] << endl;
	}
}
