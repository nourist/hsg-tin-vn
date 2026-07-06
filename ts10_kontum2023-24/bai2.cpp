#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int dp[6][(int)1e6 + 8];
int a[(int)1e6 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	int res = 1e9;
	for (int i = 0; i <= k; i++) {
		int j = n - k + i;
		res = min(res, abs(a[j] - a[i+1]));
	}
	cout << res;
}
