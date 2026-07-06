#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll dp[(int)1e4];
ll a[(int)1e4];
ll b[(int)1e4];
ll c[(int)1e4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n;
	cin >> n;

	for (ll i = 1; i <= n; i++)cin >> a[i] >> b[i] >> c[i];
	for (ll i = 1; i <= n; i++) {
		dp[i] = c[i];
		for (ll j = 1; j < i; j++) {
			if (a[i] >= b[j]) {
				dp[i] = max(dp[i], dp[j] + c[i]);
			}
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);
}
