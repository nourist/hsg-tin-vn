#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'

int a[200], dp[108][108];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, v;
	cin >> n;

	cin >> dp[1][1];
	for (int i = 2; i <= n; i++) {
		cin >> v;
		dp[i][1] = dp[i - 1][1] + v;
		for (int j = 2; j < i; j++) {
			cin >> v;
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v;
		}
		cin >> v;
		dp[i][i] = dp[i - 1][i - 1] + v;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dp[n][i]);
	}
	cout << res;
}
