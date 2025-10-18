#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 10], dp[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("DPFROg1.inp", "r", stdin);
	freopen("DPFROg1.out", "w", stdout);

	int n, k = 2;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1e9;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 1)
				dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
		}
	}
	cout << dp[n];
}
