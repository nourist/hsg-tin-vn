#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll dp[70];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i <= 64; i++) {
		dp[i] = dp[i-3]+ dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}
