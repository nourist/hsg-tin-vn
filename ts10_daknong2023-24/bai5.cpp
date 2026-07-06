#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n;

bool ok(ll k) {
	ll tai = 0, hung = 0;
	ll t = n;
	while (t != 0) {
		ll tailay = min(k, t);
		tai += tailay;
		t -= tailay;
		ll hunglay = t / 10;
		hung += hunglay;
		t -= hunglay;
	}
	return tai >= (n+1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	cin >> n;
	ll l = 0, r = 1e18,res = 1e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = min(res, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res;
}
