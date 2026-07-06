#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int p[(int)1e6 + 6], a[(int)1e6 + 6], f[(int)1e6 + 6];

int divisors(int x) {
	int res = 1;
	while (x > 1) {
		int cnt = 0, t = p[x];
		while (x % t == 0) {
			x /= t;
			cnt++;
		}
		res *= (cnt + 1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	FOR(i, 1, 1e6)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i] == i) {
			for (int j = i * i; j <= 1e6; j += i) {
				if (p[j] == j)p[j] = i;
			}
		}
	}

	int n, q;
	cin >> n >> q;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)f[i] = divisors(a[i]) + f[i - 1];

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << f[r] - f[l - 1] << '\n';
	}
}
