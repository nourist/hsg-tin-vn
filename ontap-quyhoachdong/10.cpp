#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'

int a[(int)1e6 + 8], dp[1008][58];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	fill(dp[0], dp[0] + 58, -1);
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++)
			dp[i][j] = dp[i - 1][j];
		for (int j = 0; j < k; j++) {
			if (dp[i - 1][j] != -1) {
				int du = (j + a[i]) % k;
				dp[i][du] = max(dp[i][du], dp[i - 1][j] + 1);
			}
		}
	}
	cout << dp[n][0];
}
