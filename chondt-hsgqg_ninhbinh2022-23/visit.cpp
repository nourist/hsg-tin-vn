#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define X first 
#define Y second 
#define pll pair<ll,ll>

pll a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("visit.inp", "r")) {
		freopen("visit.inp", "r", stdin);
		freopen("visit.out", "w", stdout);
	}

	ll n, b;
	cin >> n >> b;

	FOR(i, 1, n) {
		cin >> a[i].X >> a[i].Y;
	}

	sort(a + 1, a + n + 1, [&](pll x, pll y) {
		return x.X < y.X;
		});

	ll res = 0;
	FOR(i, 1, n) {
		ll l = 0, r = a[i].Y, sum = 0;

		while (l <= r) {
			ll mid = l + r >> 1;

			if (mid * a[i].X <= b) {
				sum = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		b -= sum * a[i].X;
		res += sum;
	}
	cout << res;
}
