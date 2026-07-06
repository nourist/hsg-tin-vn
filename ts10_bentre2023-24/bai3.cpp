#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			ll ned = m * 3 - a[i] - a[j];
			res += upper_bound(a + j + 1, a + n + 1, ned) - lower_bound(a + j + 1, a + n + 1, ned);
		}
	}
	cout << res;
}
