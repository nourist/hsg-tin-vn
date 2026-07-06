#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int t[(int)1e5 + 10], r[(int)1e5 + 10], dp[2][(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("dpbuytick.inp", "r", stdin);
	freopen("dpbuytick.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> t[i];
	for (int i = 1; i < n; i++)cin >> r[i];

	dp[0][1] = dp[1][1] = t[1];

	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[1][i - 1] - t[i - 1] + r[i - 1];
		dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + t[i];
	}
	cout << min(dp[1][n], dp[0][n]);
}
