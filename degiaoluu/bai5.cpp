#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll a[202][202];
ll f[202][202];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	ll n, m, k;
	cin >> n >> m >> k;
	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];
	FOR(i, 1, n)FOR(j, 1, m)f[i][j] = f[i - 1][j] + a[i][j];

	ll res = 0;
	FOR(i, 1, n)FOR(j, i, n) {
		ll sum = 0;
		ll l = 1, r = 1;
		while (r <= m) {
			sum += f[j][r] - f[i - 1][r];
			while (sum >= k) {
				sum -= f[j][l] - f[i - 1][l];
				l++;
			}

			res = max(res, (r - l + 1) * (j - i + 1));

			r++;
		}
	}

	cout << res;
}
