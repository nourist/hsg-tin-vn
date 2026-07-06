#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n;
int a[(int)1e6 + 6];
int dp[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	while (cin >> n) {
		for (int i = 1; i <= n; i++)cin >> a[i];
		int s1 = -1e9, s2 = 0;
		for (int i = 1; i <= n; i++) {
			int t = s2;
			s2 = max({0,s2, s1 - a[i]});
			s1 = max({ 0,s1, t + a[i] });
			// cout << s1 << ' ' << s2 << endl;
			dp[i] = max({ dp[i - 1], s1,s2 });
		}
		cout << dp[n] << endl;
	}
}
