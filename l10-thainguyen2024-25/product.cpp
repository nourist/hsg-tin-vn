#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 5];
ll cost[(int)1e5 + 5][3];
ll dp[(int)1e5 + 5][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("product.inp", "r")) {
		freopen("product.inp", "r", stdin);
		freopen("product.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		cost[i][0] = abs(a[i] + 1);
		cost[i][1] = abs(a[i] - 1);
	}

	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + cost[i][0];
		dp[i][1] = min(dp[i - 1][1] + cost[i][1], dp[i - 1][0] + cost[i][0]);
		// cout << cost[i][0] << ' ' << cost[i][1] << endl;
		// cout << dp[i][0] << ' ' << dp[i][1] << endl;
	}

	cout << dp[n][1];
}
