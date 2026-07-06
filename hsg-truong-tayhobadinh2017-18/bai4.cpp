#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int dp[103][(int)1e4 + 4], a[103], b[103], c[103];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n)cin >> a[i] >> b[i] >> c[i];

	FOR(i, 1, n)FOR(t, 0, c[i])FOD(j, m, 0)if (j - t * a[i] >= 0)dp[i][j] = max(dp[i][j], dp[i - 1][j - t * a[i]] + t * b[i]);

	int res = *max_element(dp[n], dp[n] + m + 1);
	int maxW = find(dp[n], dp[n] + m + 1, res) - dp[n];

	cout << maxW << ' ';
	cout << res << endl;
	// FOR(i, 1, 20)cout << dp[i] << ' ';

	vector<int> used(n + 1, 0);
	FOD(i, n, 1) {
		FOD(t, c[i], 0) {
			if (maxW - t * a[i] >= 0 && dp[i - 1][maxW - t * a[i]] + t * b[i] == dp[i][maxW]) {
				maxW -= t * a[i];
				used[i] = t;
				break;
			}
		}
	}
	FOR(i, 1, n)cout << used[i] << endl;
}
