#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, a[(int)1e6 + 6], dp[(int)1e6 + 6][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	dp[1][1] = a[1];
	dp[1][2] = -1e12;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3] });
		dp[i][1] = dp[i - 1][0] + a[i];
		dp[i][2] = dp[i - 1][1] + a[i];
		dp[i][3] = dp[i - 1][2] + a[i];
	}
	cout << max({
		dp[n][0],dp[n][1],dp[n][2],dp[n][3]
		});
}
