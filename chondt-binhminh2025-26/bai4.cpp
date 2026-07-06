#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll n, m;
int a[(int)1e5 + 5];
ll f[(int)1e5 + 5];

bool ok(ll k) {
	int r = a[1] + k;
	auto it = upper_bound(a + 1, a + n + 1, r) - a;
	return f[it - 1] + (n - it + 1) * r >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> n >> m;

	FOR(i, 1, n) cin >> a[i];

	sort(a + 1, a + n + 1);

	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	ll l = 0, r = 1e9, res = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res;
}