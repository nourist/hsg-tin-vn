#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, a[3008], l[3008], r[3008], dp[3008][3008];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("giangsinh.inp", "r", stdin);
	freopen("giangsinh.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	for (int i = 1; i <= n; i++)if (l[a[i]] == 0)l[a[i]] = i;
	for (int i = n; i >= 1; i--)if (r[a[i]] == 0)r[a[i]] = i;

	for (int len = 1; len <= n; len++) {
		for (int j = len; j <= n; j++) {
			int i = j - len + 1;
			if ((n - len + 1) % 2 == 0) {
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			}
			else {
				dp[i][j] = max(
					dp[i + 1][j] + (l[a[i]] >= i && r[a[i]] <= j),
					dp[i][j - 1] + (l[a[j]] >= i && r[a[j]] <= j));
			}
		}
	}

	cout << dp[1][n] << ':' << set<int>(a + 1, a + n + 1).size() - dp[1][n];
}