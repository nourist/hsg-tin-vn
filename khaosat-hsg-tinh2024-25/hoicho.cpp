#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll a[5005], c[(int)1e5 + 5], dp[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("hoicho.inp", "r")) {
		freopen("hoicho.inp", "r", stdin);
		freopen("hoicho.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m)cin >> c[i];

	sort(a + 1, a + n + 1);

	FOR(i, 1, n)dp[i] = 1e10;
	FOR(i, 1, n) {
		ll mn = 1e10;
		FOD(j, i - 1, 0) {
			mn = min(mn, dp[j]);
			dp[i] = min(dp[i], mn + c[a[i] - a[j + 1] + 1]);
		}
	}
	cout << dp[n];
}
