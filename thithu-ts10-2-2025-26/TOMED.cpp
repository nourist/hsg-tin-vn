#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll n, s;
ll a[(ll)2e5 + 5];

bool ok(ll x) {
	ll mid = (n+1) / 2;
	ll sum = 0;
	FOR(i, mid, n) {
		if (a[i] < x)sum += x - a[i];
	}
	return sum <= s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("TOMED.inp", "r")) {
		freopen("TOMED.inp", "r", stdin);
		freopen("TOMED.out", "w", stdout);
	}

	cin >> n >> s;
	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1);

	ll l = 1, r = 2e9, res = 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = max(res, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res;
}
