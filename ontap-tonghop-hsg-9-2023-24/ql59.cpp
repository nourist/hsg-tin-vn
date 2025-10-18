#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name ""

ll n, m, k;

ll up(ll a, ll b) {
	return ((a - 1) >= b ? (b * a - b * (b + 1) / 2) : ((a - 1) * a - (a - 1) * ((a - 1) + 1) / 2 + b - (a - 1)));
}

bool ok(ll x) {
	ll sum = x + up(x, k - 1) + up(x, n - k);
	return m >= sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen(name".inp", "r", stdin);
	// freopen(name".out", "w", stdout);

	cin >> n >> m >> k;

	ll l = 1, r = 1e9, mid;
	ll res = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (ok(mid)) {
			res = max(res, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res;
}
