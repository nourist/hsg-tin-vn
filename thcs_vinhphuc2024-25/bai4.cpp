#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)4e5 + 5];
ll dp[(int)4e5 + 5][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++)cin >> a[i];

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = max(dp[i - 1][1], 0LL) + a[i];
		dp[i][2] = max({ dp[i - 1][1], dp[i - 1][2], 0LL }) + a[i] * x;
		dp[i][3] = max({ dp[i - 1][2], dp[i - 1][3], 0LL }) + a[i];
		res = max({ res, dp[i][1], dp[i][2], dp[i][3] });
	}
	cout << res;
}
