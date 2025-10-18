#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int dp[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	string str;
	cin >> str;
	int n = str.size();
	str = "_" + str;
	
	if (str[1] == '0') {
		cout << 0;
		return 0;
	}

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (str[i] - 48 != 0)
			dp[i] += dp[i - 1];
		int num = (str[i - 1] - 48) * 10 + str[i] - 48;
		if (num >= 10 && num <= 26)
			dp[i] += dp[i - 2];
	}
	cout << dp[n];
}