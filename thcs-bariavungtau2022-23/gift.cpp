#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e4 + 9], dp[(int)1e4 + 9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("gift.inp", "r")) {
		freopen("gift.inp", "r", stdin);
		freopen("gift.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] - k >= a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);
}
