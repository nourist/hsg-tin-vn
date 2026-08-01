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
#define Name "PEARL"

int n, k;
int a[2003];
int f[2003];
ll before_dp[2003];
ll dp[2003];

ll cost(int i, int j) {
	return 1LL * (f[j] - f[i - 1]) * (f[j] - f[i - 1]);
}

void solve(int l, int r, int otpL, int otpR) {
	if (l > r)return;

	int mid = l + r >> 1;

	pll best = { 1e18, -1 };
	FOR(i, otpL, min(mid, otpR)) {
		best = min(best, { before_dp[i - 1] + cost(i, mid),i });
	}

	dp[mid] = best.X;
	solve(l, mid - 1, otpL, best.Y);
	solve(mid + 1, r, best.Y, otpR);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)a[i + n] = a[i];
	FOR(i, 1, n * 2)f[i] = f[i - 1] + a[i];

	ll res = 1e18;
	FOR(st, 1, n) {
		FOR(i, st, st + n - 1) {
			before_dp[i] = cost(st, i);
		}

		FOR(i, 2, k) {
			solve(st, st + n - 1, st, st + n - 1);
			FOR(i, st, st + n - 1)before_dp[i] = dp[i];
		}

		res = min(res, dp[st + n - 1]);
	}
	cout << res;
}
