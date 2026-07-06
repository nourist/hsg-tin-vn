#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first
#define L second

pii a[(int)1e5 + 5];
int dp[(int)1e5 + 5];
int f[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("ROBOTS.inp", "r")) {
		freopen("ROBOTS.inp", "r", stdin);
		freopen("ROBOTS.out", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n) cin >> a[i].X >> a[i].L;

	sort(a + 1, a + n + 1, [&](pii x, pii y) {
		return x.X + x.L < y.X + y.L;
		});

	FOR(i, 1, n)f[i] = a[i].X + a[i].L;

	FOR(i, 1, n) {
		int pos = upper_bound(f + 1, f + n + 1, a[i].X - a[i].L) - f - 1;
		dp[i] = max(dp[i - 1], dp[pos] + 1);
	}

	cout << *max_element(dp + 1, dp + n + 1);
}
