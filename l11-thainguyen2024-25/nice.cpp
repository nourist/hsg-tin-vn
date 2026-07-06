#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5];
int dp[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("nice.inp", "r")) {
		freopen("nice.inp", "r", stdin);
		freopen("nice.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = n; i >= 1; i--) {
		if (a[i] > n - i) {
			dp[i] = dp[i + 1] + 1;
		}
		else {
			dp[i] = min(dp[i + 1] + 1, dp[i + a[i] + 1]);
		}
	}
	cout << dp[1];
}
