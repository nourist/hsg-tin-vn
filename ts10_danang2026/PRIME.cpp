#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool p[(int)1e7 + 7];
int f[(int)1e5 + 5];

bool ok(int n) {
	bool yes = 0;
	FOR(i, 0, 9) {
		if (p[n * 10 + i])yes = 1;
	}

	if (!yes)return 0;

	while (n > 0) {
		if (!p[n])return 0;

		n /= 10;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PRIME.inp", "r")) {
		freopen("PRIME.inp", "r", stdin);
		freopen("PRIME.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;

	for (int i = 2; i * i <= 1e7; i++)if (p[i])for (int j = i * i; j <= 1e7; j += i)p[j] = 0;

	int n, a;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a;
		f[i] = f[i - 1] + ok(a);
	}

	int m, u, v;
	cin >> m;
	while (m--) {
		cin >> u >> v;
		cout << f[v] - f[u - 1] << '\n';
	}
}
