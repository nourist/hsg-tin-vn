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
#define Name "b1"

int n, k;
ll a[333];
ll dp[333][333][155];

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

	FOR(i, 1, n)FOR(j, 1, n)FOR(h, 1, k)dp[i][j][h] = -1e18;

	FOR(len, 1, n) {
		FOR(i, 1, n - len + 1) {
			int j = i + len - 1;
			FOR(h, 0, k)
				dp[i][j][h] = max(dp[i + 1][j][h], dp[i][j - 1][h]);
			if (len >= 2)FOR(h, 1, k)dp[i][j][h] = max({ dp[i][j][h],
			dp[i + 1][j - 1][h - 1] + abs(a[i] - a[j]),
			dp[i + 2][j][h - 1] + abs(a[i] - a[i + 1]),
			dp[i][j - 2][h - 1] + abs(a[j] - a[j - 1])
				});
		}
	}
	cout << dp[1][n][k];
}
