#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll n, k, m, a[5005], dp[5005][5005], f[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> n >> k >> m;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	FOR(i, 0, n)FOR(j, 0, k)dp[i][j] = -1e18;
	FOR(i, 0, n)dp[i][0] = 0;

	FOR(i, 1, n) {
		FOR(j, 1, k) {
			dp[i][j] = dp[i - 1][j];

			if (i - m >= 0)dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + f[i] - f[i - m]);
		}
	}

	cout << dp[n][k];
}

/*
dp[i][j] = giá trị tốt nhất khi xét đến vị trí i và đang xét j đoạn con
- dp[i][j] = dp[i-1][j]
- dp[i][j] = dp[x][j-1] + sum

*/