#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n;
int a[(int)1e5 + 5];
int l[(int)1e5 + 5];
int r[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PROFIT.inp", "r")) {
		freopen("PROFIT.inp", "r", stdin);
		freopen("PROFIT.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n) {
		l[i] = l[i - 1] + a[i];
		if (l[i] > 0)l[i] = 0;
	}
	FOD(i, n, 1) {
		r[i] = r[i + 1] + a[i];
		if (r[i] > 0)r[i] = 0;
	}

	FOR(i, 1, n) {
		l[i] = min(l[i], l[i - 1]);
	}
	FOD(i, n, 1) {
		r[i] = min(r[i], r[i + 1]);
	}

	ll sum = accumulate(a + 1, a + n + 1, 0);
	ll res = 0;
	FOR(i, 1, n - 1) {
		res = max(res, sum - l[i] * 2 - r[i + 1] * 2);
	}
	cout << res;
}
