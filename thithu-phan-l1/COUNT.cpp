#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int p[(int)1e6 + 6];
int r[(int)1e6 + 6];
int f[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("COUNT.inp", "r")) {
		freopen("COUNT.inp", "r", stdin);
		freopen("COUNT.out", "w", stdout);
	}

	FOR(i, 1, 1e6)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i] == i) {
			for (int j = i * i; j <= 1e6; j += i) {
				if (p[j] == j) {
					p[j] = i;
				}
			}
		}
	}

	FOR(i, 1, 1e6) {
		int n = i;
		int res = 1;

		while (n != 1) {
			int cnt = 0;
			int cur = p[n];

			while (n % cur == 0) {
				cnt++;
				n /= cur;
			}

			if (cnt % 2 == 1) {
				res *= cur;
			}
		}

		r[i] = res;
	}

	int n;
	cin >> n;

	FOR(i, 1, n) {
		f[r[i]]++;
	}

	ll res = 0;
	FOR(i, 1, 1e6) {
		res += f[i] * (f[i] - 1) * (f[i] - 2) / 6;
	}
	cout << res;
}
