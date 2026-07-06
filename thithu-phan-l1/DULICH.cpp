#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, k;
int f[(int)1e5 + 5];

bool ok(int x, int mid) {
	int r = min(n, x + mid);
	int l = max(1, x - mid);

	return r - l + 1 - (f[r] - f[l - 1]) >= k + 1;
}

int solve(int x) {
	int l = 1, r = n, res = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(x, mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DULICH.inp", "r")) {
		freopen("DULICH.inp", "r", stdin);
		freopen("DULICH.out", "w", stdout);
	}

	string s;
	cin >> n >> k >> s;

	FOR(i, 1, n) {
		f[i] = f[i - 1] + (s[i - 1] - '0');
	}

	int res = n;
	FOR(i, 1, n) {
		if (s[i - 1] == '0') {
			res = min(res, solve(i));
		}
	}
	cout << res;
}
