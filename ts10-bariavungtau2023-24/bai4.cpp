#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll dp[1024*4+8];
ll a[1008], b[1008];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;
	k *= 1024;
	for (ll i = 1; i <= n; i++)cin >> a[i] >> b[i];

	for (ll i = 1; i <= k; i++) {
		for (ll j = 1; j <= n; j++) {
			if(i>=a[j])
				dp[i] = max(dp[i - a[j]] + b[j], dp[i]);
		}
	}
	cout << *max_element(dp+1,dp+k+1);
}
