#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll d[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll l, r, p;
	cin >> l >> r >> p;
	FOR(i, 0, 9) d[i] = r / 10 - (l - 1) / 10;
	FOR(i, 0, r % 10) d[i]++;
	FOR(i, 0, (l - 1) % 10)d[i]--;

	ll res = 0;
	FOR(i, 0, 9)FOR(j, 0, 9) {
		res += d[i] * d[j] * (i * j % 10 == p);
	}
	cout << res;
}
