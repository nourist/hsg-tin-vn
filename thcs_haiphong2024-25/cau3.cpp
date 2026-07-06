#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

pair<int, int>a[(int)1e5];
int dp[(int)1e5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[j].first >= a[i].second)dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp,dp+n);
}
