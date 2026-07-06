#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll a, n;
ll b[50];

bool ok(ll x) {
	ll cnt = 0;
	FOR(i, 1, n)cnt += x / b[i];
	return cnt >= a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("CAKES.inp", "r")) {
		freopen("CAKES.inp", "r", stdin);
		freopen("CAKES.out", "w", stdout);
	}

	cin >> a >> n;
	FOR(i, 1, n)cin >> b[i];

	ll l = 0, r = 1e15, res = 1e15;
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
