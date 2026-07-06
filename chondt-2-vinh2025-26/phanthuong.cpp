#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first
#define Y second

pii a[(int)1e2 + 2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("phanthuong.inp", "r")) {
		freopen("phanthuong.inp", "r", stdin);
		freopen("phanthuong.out", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n)cin >> a[i].X;
	FOR(i, 1, n)cin >> a[i].Y;

	int res1 = 0;
	FOR(i, 1, n) {
		if (a[i].Y == 2)a[i].X = -a[i].X;
		res1 += a[i].X;
		a[i].X = abs(a[i].X);
	}
	cout << abs(res1) << endl;

	bitset<(int)2e6 + 6>dp;
	dp[(int)1e6] = 1;
	FOR(i, 1, n) {
		dp = (dp << a[i].X) | (dp >> a[i].X);
	}

	int res2 = 1e9;
	FOR(i, -1e6, 1e6) {
		if (dp[(int)1e6 + i]) {
			res2 = min(res2, abs(i));
		}
	}
	cout << res2;
}
