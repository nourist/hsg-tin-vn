#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5];
int dp[(int)1e5 + 5];
int q[(int)1e5 + 5];
int h[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n)q[i] = -a[i];
	FOR(i, 2, n)q[i] = max(q[i], q[i - 1]);

	FOR(t, 1, k) {
		FOR(i, 2, n) {
			dp[i] = max(dp[i], q[i - 1] + a[i]);
			h[i] = max(h[i - 1], dp[i]);
		}
		FOR(i, 2, n) {
			q[i] = max(q[i - 1], h[i - 1] - a[i]);
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);
}

/*
dp[i][j] lợi nhuận lớn nhất khi thực hiện j giao dịch tại thời điểm i

dp[i][j] = dp[i][j-1]

dp[i][j] = a[i] + max(dp[k-1][j-1] - a[k])

*/