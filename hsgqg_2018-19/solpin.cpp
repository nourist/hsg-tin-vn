#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 

int a[(int)1e3 + 3][(int)1e3 + 3];
ll f[(int)1e3 + 3][(int)1e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("solpin.inp", "r")) {
		freopen("solpin.inp", "r", stdin);
		freopen("solpin.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n)FOR(j, 1, m) {
		cin >> a[i][j];
		a[i + n][j] = a[i][j + m] = a[i + n][j + m] = a[i][j];
	}

	FOR(i, 1, n * 2)FOR(j, 1, m * 2) {
		f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
	}

	// FOR(i, 1, n * 2)FOR(j, 1, m * 2)cout << a[i][j] << " \n"[j == m * 2];

	pii cur = { 1,1 };

	int q;
	cin >> q;

	while (q--) {
		int p, x, y, u, v, s, t;
		cin >> p;

		if (p == 0) {
			cin >> y >> x;

			x %= n;
			y %= m;

			cur.X += x;
			cur.Y += y;

			if (cur.X > n) cur.X -= n;
			if (cur.Y > m) cur.Y -= m;
		}
		else {
			cin >> u >> v >> s >> t;
			u += cur.X - 1;
			s += cur.X - 1;
			v += cur.Y - 1;
			t += cur.Y - 1;

			// cout << u << ' ' << v << ' ' << s << ' ' << t << endl;

			cout << f[s][t] - f[u - 1][t] - f[s][v - 1] + f[u - 1][v - 1] << '\n';
		}
	}
}
