#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[108], u[108];
bool dp[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> u[i];
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		if (u[i] == 1)sum += a[i];
		else sum -= a[i];
	}

	cout << abs(sum) << endl;

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for(int j = 1e6; j >= a[i]; j--) {
			if (dp[j - a[i]])dp[j] = 1;
		}
	}
	sum = accumulate(a + 1, a + n + 1, 0);
	int res = 1e9;
	for (int i = 1; i <= 1e6; i++) {
		if(dp[i])
		res = min(res, abs(sum - i * 2));
	}
	cout << res;
}
