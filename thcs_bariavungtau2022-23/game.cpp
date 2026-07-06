#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5], dp[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("game.inp", "r")) {
		freopen("game.inp", "r", stdin);
		freopen("game.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)cin >> a[i];

	fill(dp + 2, dp + n + 1, 1e9);
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= min(i + k, n); j++) {
			dp[j] = min(dp[j], dp[i] + abs(a[i] - a[j]));
		}
	}
	cout << dp[n];
}
