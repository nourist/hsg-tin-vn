#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define X first
#define Y second

pii v[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> v[i].X >> v[i].Y;

	sort(v + 1, v + n + 1, [&](pii a, pii b) {
		return (ld)a.X / a.Y > (ld)b.X / b.Y;
		});

	ll res = 0;
	FOR(i, 1, n)res += 1LL * v[i].X * (i - 1) + 1LL * v[i].Y * (n - i);
	cout << res;
}

/*
a*(j-1) + b*(n-j)
a*(j-1) + b*n - b - b*j + b
(a+b)*(j-1) + b*(n-1)
*/
