#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e6 + 6];
ll dp[(int)1e6 + 6][3];// đang lấy j lần liên tiếp 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("TRANS.inp", "r")) {
		freopen("TRANS.inp", "r", stdin);
		freopen("TRANS.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n) {
		dp[i][0] = max({ dp[i - 1][0],dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = dp[i - 1][0] + a[i];
		dp[i][2] = dp[i - 1][1] + a[i];
	}

	cout << max({ dp[n][0], dp[n][1], dp[n][2] });
}
