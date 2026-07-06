#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll h[55], g[55];
ll dp[55];

ll n, k;
ll res = 0;

void Try(ll idx, ll sum) {
	if (sum >= k)res++;

	FOR(i, idx + 1, n) {
		if (h[i] >= h[idx] && sum + dp[i] >= k) {
			Try(i, sum + g[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("GAME.inp", "r")) {
		freopen("GAME.inp", "r", stdin);
		freopen("GAME.out", "w", stdout);
	}

	cin >> n >> k;

	FOR(i, 1, n)cin >> h[i] >> g[i];

	FOD(i, n, 1) {
		dp[i] = g[i];

		FOR(j, i + 1, n) {
			if (h[j] >= h[i]) {
				dp[i] = max(dp[i], dp[j] + g[i]);
			}
		}
	}

	Try(0, 0);

	cout << res << endl;
}
