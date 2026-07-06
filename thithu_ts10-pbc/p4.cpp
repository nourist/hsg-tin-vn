#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll w[1003], v[1003], a[1003], dp[10004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("p4.inp", "r")) {
		freopen("p4.inp", "r", stdin);
		freopen("p4.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;
	FOR(i, 1, n)cin >> w[i] >> v[i] >> a[i];

	FOR(i, 1, n) {
		ll count = a[i];
		for (ll k = 1; count>=1; k *= 2) {
			ll use = min(count, k);
			ll weight = w[i] * use;
			ll reward = v[i] * use;
			count -= use;

			FOD(j, m, weight) {
				dp[j] = max(dp[j], dp[j - weight] + reward);
			}
		}
	}
	cout << *max_element(dp, dp + m + 1);
}
