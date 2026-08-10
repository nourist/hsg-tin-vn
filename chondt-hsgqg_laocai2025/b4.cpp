#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b4"

int n, k;
int a[(int)3e5 + 5];

namespace sub0 {
	void solve() {
		cout << accumulate(a + 1, a + n + 1, 0LL);
	}
}

namespace sub1 {
	void solve() {
		ll sum = 0;
		FOR(i, 1, n)if (a[i] > 0)sum += a[i];
		cout << sum;
	}
}

namespace sub2 {
	void solve() {
		ll sum = 0;
		ll res = 0;
		FOR(i, 1, n) {
			sum += a[i];
			res = max(res, sum);
			if (sum < 0)sum = 0;
		}
		cout << res;
	}
}

namespace sub5 {
	ll f[2002];
	ll dp[2002], ndp[2002];

	void solve() {
		FOR(i, 1, n) f[i] = f[i - 1] + a[i];

		ll sum = 0;
		FOR(i, 1, n) {
			sum += a[i];
			dp[i] = max(dp[i - 1], sum);
			if (sum < 0)sum = 0;
		}

		FOR(t, 1, k - 1) {
			ll max_prev = dp[0] - f[0];
			FOR(i, 1, n) {
				ndp[i] = dp[i];
				ndp[i] = max(ndp[i], max_prev + f[i]);
				max_prev = max(max_prev, dp[i] - f[i]);
			}

			FOR(i, 1, n) dp[i] = ndp[i];
			FOR(i, 2, n) dp[i] = max(dp[i], dp[i - 1]);
		}
		cout << dp[n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	int cntNeg = 0;
	FOR(i, 1, n)if (a[i] < 0)cntNeg++;

	if (k == 1)sub2::solve();
	else if (cntNeg == 0)sub0::solve();
	else if (cntNeg == 1)sub1::solve();
	else sub5::solve();
}
