#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name "LONGDEN"

ll a[(ll)1e5 + 8];
ll n, m;

bool ok(ll x) {
	ll h = n;
	for (ll i = 0; i < m; i++) {
		h -= ceil((ld)a[i] / x);
	}
	return h >= 0;
}

int main() {
	freopen(name".INP", "r", stdin);
	freopen(name".OUt", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (ll i = 0; i < m; i++)cin >> a[i];

	ll l = 1, r = 1e14;

	ll res = LONG_LONG_MAX;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = min(res, mid);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << res;
}
