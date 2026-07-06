#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll a[(int)1e5 + 5], f[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	ll n, l, r;
	cin >> n >> l >> r;

	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) f[i] = f[i - 1] + a[i];

	ll res = 0;
	FOR(i, 1, n) {
		ll x = f[i] - r;
		ll y = f[i] - l;
		int u = lower_bound(f, f + i, x) - f;
		int v = upper_bound(f, f + i, y) - f;
		res += (v - u);
	}
	cout << res;
}

/*
5 4 8
1 2 3 4 5
1 3 6 10 15
s = f[i] - f[j-1]
s>=l and s<=r
f[i] - r <= f[j-1] <= f[i] - l
*/