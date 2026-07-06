#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, f[(int)2e5 + 5], R[(int)2e5 + 5];
string s;

bool ok(int k) {
	int l = 1, r = 1;
	int cnt = 0;

	while (r <= n) {
		if (s[r] == 'C')cnt++;

		while (cnt > k) {
			if (s[l] == 'C')cnt--;
			l++;
		}

		if (f[l - 1] + f[n] - f[r] <= k)return 1;

		r++;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> s;

	n = s.size();
	s = "_" + s;

	FOR(i, 1, n)f[i] = f[i - 1] + (s[i] == 'P');

	// ok(2);

	int l = 0, r = n, res = n;
	while (l <= r) {
		int mid = (l + r) / 2;
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

/*
s = max(c, (n(p)-p))

*/
