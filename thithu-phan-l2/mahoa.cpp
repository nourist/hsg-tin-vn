#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll dp[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("mahoa.inp", "r")) {
		freopen("mahoa.inp", "r", stdin);
		freopen("mahoa.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	dp[0] = 1;
	FOR(i, 1, n) {
		FOR(j, 1, k) {
			if (i - j >= 0)
				dp[i] += dp[i - j];
		}
	}

	cout << dp[n] * 2;
}
