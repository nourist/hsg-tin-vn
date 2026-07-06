#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define db double
#define X first
#define Y second
#define Name "BMARK"

int n, k;
int a[(int)3e5 + 5];
db f[(int)3e5 + 5];

bool ok(db m) {
	memset(f, 0, sizeof f);
	FOR(i, 1, n)f[i] = f[i - 1] + a[i] - m;

	db mi = 1e18, res = -1e18;
	FOR(i, k, n) {
		mi = min(mi, f[i - k]);
		res = max(res, f[i] - mi);
	}
	return res >= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	db l = 1, r = 1e6 + 1, res = 1;
	while (r - l >= 1e-9) {
		db mid = (l + r) / 2;

		if (ok(mid)) {
			res = mid;
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << fixed << setprecision(6) << round(res * 1000000) / 1000000.0;
}