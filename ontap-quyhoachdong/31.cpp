#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int dp[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("DPLAGA1.inp", "r", stdin);
	freopen("DPLAGA1.out", "w", stdout);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1e6; i++)dp[i] = (dp[i - 1] + dp[i - 2]) % ((int)1e9 + 7);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}
