#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5];
int b[(int)1e2 + 2];
ll f[(int)1e5 + 5];
ll dp[(int)1e5 + 5][(int)1e2 + 2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("chungkhoan.inp", "r")) {
		freopen("chungkhoan.inp", "r", stdin);
		freopen("chungkhoan.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m)cin >> b[i];

	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	FOR(i, 1, n)FOR(j, 1, m) {
		dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1] });
		dp[i][j] = max(dp[i][j], dp[i - b[j]][j - 1] + (f[i] - f[i - b[j]]));
	}

	cout << dp[n][m];
}
