#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "APEN"

int n, q;
int a[(int)1e5 + 5];
ll f[(int)1e5 + 5];

ll get(ll x, ll m, ll k) {
	int y = m - x;
	return f[x] + 2 * k * y - f[n] + f[n - y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> q;

	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1);

	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	while (q--) {
		int k, m;
		cin >> k >> m;

		int l = 0, r = m;
		while (r - l >= 3) {
			int mid1 = l + (r - l) / 3;
			int mid2 = r - (r - l) / 3;

			if (get(mid1, m, k) > get(mid2, m, k)) {
				l = mid1;
			}
			else {
				r = mid2;
			}
		}

		ll res = 1e18;
		FOR(i, l, r) {
			res = min(res, get(i, m, k));
		}
		cout << res << '\n';
	}
}