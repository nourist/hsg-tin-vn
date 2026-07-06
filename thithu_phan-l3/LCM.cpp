#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

const int mod = 1e9 + 7;
int p[(int)1e6 + 6];
int f[(int)1e6 + 6];

void factorize(int n) {
	while (n != 1) {
		f[p[n]]++;
		n /= p[n];
	}
}

void solve() {
	int a, b;
	cin >> a >> b;

	memset(f, 0, sizeof f);
	FOR(i, a, b)factorize(i);

	ll res = 1;
	FOR(i, 1, 1e6) {
		res = res * (f[i] * 2 + 1) % mod;
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("LCM.inp", "r")) {
		freopen("LCM.inp", "r", stdin);
		freopen("LCM.out", "w", stdout);
	}

	FOR(i, 1, 1e6)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++)
		if (p[i] == i)
			for (int j = i * i; j <= 1e6; j += i)
				if (p[j] == j)
					p[j] = i;

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
