#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, k, a[(int)1e5 + 5];

bool ok2(ll x) {
	ll sum = 0;
	FOR(i, 1, n) {
		sum += k * x;
		if (sum < a[i]) {
			return false;
		}
		sum -= a[i];
	}
	return true;
}

bool ok1(ll x) {
	ll sum = 0;
	FOD(i, n, 1) {
		sum += a[i];
		if (x * k * (n - i + 1) >= sum) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("b3.inp", "r")) {
		freopen("b3.inp", "r", stdin);
		freopen("b3.out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];

	ll l = 0, r = 1e14 / k + 1, res = 1e14;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok1(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res << ' ';

	l = 0; r = 1e14 / k + 1; res = 1e14;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok2(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res;
}
