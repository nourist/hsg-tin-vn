#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, k;
int a[(int)1e5 + 5];

bool ok(ll x) {
	ll cnt = 0, sum = 0;
	FOR(i, 1, n) {
		if (a[i] > x)return false;
		if (sum + a[i] > x) {
			cnt++;
			sum = a[i];
		}
		else sum += a[i];
	}
	if (sum > 0)cnt++;
	return cnt <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	cin >> n >> k;

	FOR(i, 1, n)cin >> a[i];

	ll l = 1, r = 1e9, res = 1e14;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = min(res, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout << res;
}