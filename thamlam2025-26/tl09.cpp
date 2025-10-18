#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

pair<int, int> v[(int)5e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("muasuabo.inp", "r")) {
		freopen("muasuabo.inp", "r", stdin);
		freopen("muasuabo.out", "w", stdout);
	}

	int m, n;
	cin >> m >> n;

	FOR(i, 1, n)cin >> v[i].first >> v[i].second;

	ll res = 0;

	sort(v + 1, v + n + 1);

	FOR(i, 1, n) {
		if (m <= 0) break;
		int x = min(m, v[i].second);
		res += 1ll * x * v[i].first;
		m -= x;
	}
	cout << res;
}
