#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e6 + 10];
ll n, m;

bool ok(int len) {
	for (int i = len; i <= n; i++) {
		if (a[i] - a[i - len] < m)return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	ll res = n + 1, l = 1, r = n;
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
	cout << (res == n + 1 ? -1 : res);
}
