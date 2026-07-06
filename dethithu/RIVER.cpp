#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, m, j;
ll d[(int)1e6 + 6];
ll f[(int)1e6 + 6];

bool ok(ll x) {
	ll i = 0, cnt = 0;
	while (i <= n) {
		ll pos = upper_bound(f + 1, f + n + 1, f[i] + x) - f;
		cnt++;
		if (pos == n + 1)break;
		i = pos - 1;
		if (cnt > j)break;
	}
	return cnt <= j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("RIVER.inp", "r")) {
		freopen("RIVER.inp", "r", stdin);
		freopen("RIVER.out", "w", stdout);
	}

	cin >> n >> m >> j;

	FOR(i, 0, n - 1)d[i + 1] = (1LL * i * i % m) + 1;
	FOR(i, 1, n)f[i] = f[i - 1] + d[i];

	// FOR(i, 1, n)cout << d[i] << ' ';
	// cout << endl;
	// FOR(i, 1, n)cout << f[i] << ' ';

	ll l = 1, r = 1e15, res = 1e15;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
	// cout << ok(1);
}
