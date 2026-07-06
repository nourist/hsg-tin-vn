#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll s, n;
ll a[100];

bool ok(ll x) {
	ll cnt = 0;
	for(ll i = 1; i <= n; i++) {
		cnt += x / a[i];
	}
	return cnt >= s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("nauan.inp", "r")) {
		freopen("nauan.inp", "r", stdin);
		freopen("nauan.out", "w", stdout);
	}

	cin >> s >> n;

	for (int i = 1; i <= n; i++)cin >> a[i];
	ll l = 0, r = 1e15, res = 1e15;
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
