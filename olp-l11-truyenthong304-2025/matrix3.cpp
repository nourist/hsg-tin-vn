#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, m, a[2155][2155], dp[2155][2155][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("matrix3.inp", "r")) {
		freopen("matrix3.inp", "r", stdin);
		freopen("matrix3.out", "w", stdout);
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			// dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1e14;
		}
	}

	dp[1][1][0] = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j + 1][0] = max({ dp[i][j][0], dp[i][j][1], dp[i][j][2] }) + a[i][j + 1];
			dp[i + 1][j][1] = dp[i][j][0] + a[i + 1][j];
			dp[i + 1][j][2] = dp[i][j][1] + a[i + 1][j];
		}
	}
	cout << max({
		dp[n][m][0],
		dp[n][m][1],
		dp[n][m][2],
		0LL
		}) << endl;
}
