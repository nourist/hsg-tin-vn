#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[2024];
int dp[2024][2024];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("noel.inp", "r")) {
		freopen("noel.inp", "r", stdin);
		freopen("noel.out", "w", stdout);
	}

	int n, d;
	cin >> n >> d;

	FOR(i, 1, n * 2)cin >> a[i];

	int res = 0;

	FOR(x, 1, n * 2 - 1) {
		memset(dp, 0, sizeof dp);
		FOR(i, 1, x)FOR(j, x + 1, n * 2) {
			if (i == j)continue;

			if (abs(a[i] - a[j]) <= d) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

			res = max(res, min(dp[i][j], abs(j - i)));
		}

	}
	cout << res;
}
