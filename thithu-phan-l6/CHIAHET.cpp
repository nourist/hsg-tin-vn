#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool p[(int)1e7 + 7];
int f[(int)1e7 + 7];

void sieve() {
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e7; i++)
		if (p[i])
			for (int j = i * i; j <= 1e7; j += i)
				p[j] = 0;
}

void update(int n, int delta) {
	FOR(i, 1, n) {
		if (!p[i])continue;

		for (int cur = i; cur <= n; cur *= i) {
			f[i] += n / cur * delta;
		}
	}
}

void solve() {
	memset(f, 0, sizeof f);

	//d - (c-1) >= b - (a-1)
	//d - (c-1) - b + (a-1) >= 0

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	update(d, 1);
	update(c - 1, -1);
	update(b, -1);
	update(a - 1, 1);

	FOR(i, 1, max(b, d)) {
		if (f[i] < 0) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("CHIAHET.inp", "r")) {
		freopen("CHIAHET.inp", "r", stdin);
		freopen("CHIAHET.out", "w", stdout);
	}

	sieve();

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
