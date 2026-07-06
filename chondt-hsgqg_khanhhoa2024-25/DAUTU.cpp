#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "dautu"

int n, m, a, b;
int c[505][505];
ll f[505][505];

ll getQ(ll s) {
	return abs(s - a) + abs(s - b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> a >> b;

	if (n > m) {
		FOR(i, 1, n)FOR(j, 1, m)cin >> c[j][i];
		swap(n, m);
	}
	else {
		FOR(i, 1, n)FOR(j, 1, m)cin >> c[i][j];
	}

	FOR(i, 1, n)FOR(j, 1, m)f[i][j] = f[i - 1][j] + c[i][j];

	ll res = 1e18;
	FOR(i, 1, n)FOR(j, i, n) {
		int l = 1;
		ll s = 0;

		FOR(r, 1, m) {
			s += f[j][r] - f[i - 1][r];

			while (l + 1 <= r && getQ(s - (f[j][l] - f[i - 1][l])) < getQ(s)) {
				s -= (f[j][l] - f[i - 1][l]);
				l++;
			}

			res = min(res, getQ(s));
		}
	}
	cout << res;
}