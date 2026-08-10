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
#define Name "DAYSO"

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

int a[5005], b[5005], dp[5005][5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	cin >> m;
	FOR(i, 1, m)cin >> b[i];

	dp[0][0] = 0;

	FOR(i, 1, n) {
		int t = i;
		if ((t & 1) != a[i]) t++;
		dp[i][0] = t;
	}

	FOR(j, 1, m) {
		int t = j;
		if ((t & 1) != b[j]) t++;
		dp[0][j] = t;
	}

	FOR(i, 1, n)FOR(j, 1, m) {
		dp[i][j] = 1e9;

		if (!a[i]) {
			int t = dp[i - 1][j] + 1;
			if (t % 2 == 1)t++;
			dp[i][j] = min(dp[i][j], t);
		}
		else {
			int t = dp[i - 1][j] + 1;
			if (t % 2 == 0)t++;
			dp[i][j] = min(dp[i][j], t);
		}

		if (!b[j]) {
			int t = dp[i][j - 1] + 1;
			if (t % 2 == 1)t++;
			dp[i][j] = min(dp[i][j], t);
		}
		else {
			int t = dp[i][j - 1] + 1;
			if (t % 2 == 0)t++;
			dp[i][j] = min(dp[i][j], t);
		}
	}

	cout << dp[n][m];
}