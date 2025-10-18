#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DPXEPHANG1.inp", "r")) {
		freopen("DPXEPHANG1.inp", "r", stdin);
		freopen("DPXEPHANG1.out", "w", stdout);
	}

	ll n, dp[100];
	cin >> n;
	dp[1] = 2;
	dp[2] = 4;
	dp[3] = 7;
	for (int i = 4; i <= n; i++)dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	cout << dp[n];
}
