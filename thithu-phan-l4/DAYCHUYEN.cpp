#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define A first 
#define B second 

pii v[(int)4e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DAYCHUYEN.inp", "r")) {
		freopen("DAYCHUYEN.inp", "r", stdin);
		freopen("DAYCHUYEN.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n * 2) {
		cin >> v[i].A >> v[i].B;
	}

	sort(v + 1, v + n * 2 + 1, [&](pii x, pii y) {
		return x.A - x.B < y.A - y.B;
		});

	ll res = 0;
	FOR(i, 1, n) {
		res += v[i].A;
	}
	FOR(i, n + 1, 2 * n) {
		res += v[i].B;
	}
	cout << res;
}
