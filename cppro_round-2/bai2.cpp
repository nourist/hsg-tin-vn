#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool p[(int)1e6 + 6];
int d[(int)1e6 + 6];
int f[(int)1e6 + 6][13];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e6; i++)
		if (p[i])
			for (int j = i * i; j <= 1e6; j += i)
				p[j] = 0;

	FOR(i, 1, 1e6)
		if (p[i])
			for (int j = i; j <= 1e6; j += i)
				d[j]++;

	FOR(i, 1, 1e6)
		if (d[i] >= 1 && d[i] <= 10)
			f[i][d[i]]++;

	FOR(i, 1, 1e6)FOR(j, 1, 10)f[i][j] += f[i - 1][j];

	int q, l, r, k;
	cin >> q;

	while (q--) {
		cin >> l >> r >> k;
		cout << f[r][k] - f[l - 1][k] << '\n';
	}
}
