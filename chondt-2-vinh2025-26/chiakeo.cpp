#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll n, m, k;

ll sumSide(ll x, ll l) {
	if (x >= l) {
		return ((x + x - l + 1) * l) / 2;
	}
	else {
		return (x * (x + 1)) / 2 + (l - (x - 1));
	}
}

bool ok(ll x) {
	ll l = k - 1;
	ll r = n - k;
	return sumSide(x - 1, l) + sumSide(x - 1, r) + x <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("chiakeo.inp", "r")) {
		freopen("chiakeo.inp", "r", stdin);
		freopen("chiakeo.out", "w", stdout);
	}

	cin >> n >> m >> k;

	ll l = 0, r = 1e9, res = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res;
}
