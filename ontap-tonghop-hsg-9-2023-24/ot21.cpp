#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name "checkin"

ll a[(ll)1e5 + 8], n, m;

bool ok(ll x) {
	ll h = m;
	for (ll i = 0; i < n; i++) {
		h -= x / a[i];
	}
	return h <= 0;
}

ll chatnhiphan(ll l, ll r) {
	ll mid, res = LONG_LONG_MAX;
	while (l <= r) {
		mid = (l + r) / 2;

		if (ok(mid)) {
			res = min(res, mid);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return res;
}

int main() {
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (ll i = 0; i < n; i++)cin >> a[i];
	cout << chatnhiphan(1, 1e14);
}
