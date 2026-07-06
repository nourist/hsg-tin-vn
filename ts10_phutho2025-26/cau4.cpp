#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5];
int dp[(int)1e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	int n, x, y;
	cin >> n >> x >> y;

	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, 1e3)dp[i] = -1;

	FOR(i, 1, n) {
		FOD(j, 1e3, a[i]) {
			if (dp[j - a[i]] != -1)dp[j] = max(dp[j], dp[j - a[i]] + 1);
		}
	}

	cout << dp[y - x];
}
