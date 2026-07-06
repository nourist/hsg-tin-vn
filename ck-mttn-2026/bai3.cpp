#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, a[505], dp[505][505];

void minz() {
	vector<int>res;
	FOR(i, 1, n) {
		if (res.empty() || res.back() != a[i]) {
			res.push_back(a[i]);
		}
	}
	n = res.size();
	FOR(i, 1, n) {
		a[i] = res[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	minz();

	FOR(l, 1, n) {
		FOR(i, 1, n - l + 1) {
			int j = i + l - 1;

			dp[i][j] = dp[i + 1][j] + 1;

			FOR(k, i + 1, j) {
				if (a[i] == a[k]) {
					dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
				}
			}
		}
	}
	cout << dp[1][n];
}
