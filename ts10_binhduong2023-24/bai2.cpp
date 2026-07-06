#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n;
ll k;
ll dp[60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	cin >> n >> k;
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= k; j++) {
			if(i-j>=0)
			dp[i] += dp[i - j];
		}
	}
	cout << dp[n];
}
