#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int mod = 1e9 + 7;

ll dp[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;

	ll res = n, sum =n;
	for (int i = 1; i <= k; i++) {
		// for (int j = i - 1; j >= 0; j--) {
		// 	dp[i] += dp[j] * (i - j);
		// 	dp[i] %= mod;
		// }
		dp[i] = dp[i - 1] + sum;
		sum += dp[i];
		sum %= mod;

		res += dp[i];
		res %= mod;
	}
	// for (int i = 0; i <= k; i++)cout << dp[i] << ' ';
	cout << res;
}
