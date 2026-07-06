#include <bits/stdc++.h>
using namespace std;

#define mod 123456789

int dp[1001][1001]; //cach chia i phan qua cho j nguoi

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	if (fopen("COREWARD.inp", "r")) {
		freopen("COREWARD.inp", "r", stdin);
		freopen("COREWARD.out", "w", stdout);
	}

	int m, n;
	cin >> m >> n;

	for (int j = 0; j <= n; ++j) dp[0][j] = 1;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i][j - 1];
			if (i >= j) dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
		}
	}

	cout << dp[m][n];
}
