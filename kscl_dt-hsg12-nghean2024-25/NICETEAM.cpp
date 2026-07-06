#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, k, a[(int)1e6 + 6];
ll f[(int)1e6 + 6];

bool ok(int x) {
	FOR(i, 1, n)f[i] = f[i - 1] + a[i] - x;
	ll prefix = 0, l = 1, r = 1, sum = 0;
	while (r <= n) {
		sum += a[r];
		while (sum >= k) {
			prefix = min(prefix, f[l - 1]);
			sum -= a[l++];
			if (f[r] >= prefix)return true;
		}
		r++;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("NICETEAM.inp", "r")) {
		freopen("NICETEAM.inp", "r", stdin);
		freopen("NICETEAM.out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	int l = 0, r = 1e9, res = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
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

/*
*/