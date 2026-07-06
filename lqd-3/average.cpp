#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, k;
int a[(int)2e5 + 5];
ld d[(int)2e5 + 5];

bool ok(ld x) {
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + (ld)a[i] - x;
	}
	ld mn = 0;

	for (int i = k; i <= n; i++) {
		if (d[i] - mn >= 0) {
			return true;
		}
		mn = min(mn, d[i - k + 1]);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("average.inp", "r")) {
		freopen("average.inp", "r", stdin);
		freopen("average.out", "w", stdout);
	}

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ld l = -2e14, r = 2e14;
	ld res = -2e14;

	while (r-l>1e-6) {
		ld mid = (l + r) / 2;
		if (ok(mid)) {
			res = max(res, mid);
			l = mid;
		}
		else {
			r = mid;
		}
	}

	cout<<fixed<<setprecision(3)<<res;
}
