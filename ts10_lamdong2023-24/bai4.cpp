#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 8], p[(int)1e6+8], dp[(int)1e6 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i < n; i++)cin >> p[i];

	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + p[i-1]);
	}
	cout << dp[n];
}
