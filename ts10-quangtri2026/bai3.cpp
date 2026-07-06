#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int p[(int)1e6 + 6];
int f[(int)1e6 + 6];

bool prime(int n) {
	for (int i = 2; i * i <= n; i++)if (n % i == 0)return 0;
	return n > 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	for (int i = 1; i * i <= 1e6; i++) {
		p[i * i]++;
		for (int j = i * (i + 1); j <= 1e6; j += i) {
			p[j] += 2;
		}
	}

	FOR(i, 1, 1e6)f[i] = f[i - 1] + prime(p[i]);

	int n, l, r;
	ll res = 0;
	cin >> n;
	FOR(i, 1, n) {
		cin >> l >> r;
		res += f[r] - f[l - 1];
	}
	cout << res;
}
