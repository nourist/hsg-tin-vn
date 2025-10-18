#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 10], dp[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("DpPLAY.inp", "r", stdin);
	freopen("DpPLAY.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i + j <= n) {
				dp[i + j] = max(dp[i + j], dp[i] + a[i + j]);
			}
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);
}
