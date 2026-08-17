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
#define Name "coin"

int dp[155][155];
pair<pii, int> trace[155][155];
pii a[25];
int cap[25];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, v, w;
	cin >> n >> v >> w;

	FOR(i, 1, n)cin >> a[i].X >> a[i].Y;

	FOR(i, 0, v)FOR(j, 0, w)dp[i][j] = 1e9;
	dp[0][0] = 0;

	FOR(idx, 1, n) {
		FOR(i, 0, v)FOR(j, 0, w) {
			if (dp[i][j] == 1e9)continue;

			int ni = i + a[idx].X;
			int nj = j + a[idx].Y;

			if (ni <= v && nj <= w && dp[i][j] + 1 <= dp[ni][nj]) {
				dp[ni][nj] = dp[i][j] + 1;
				trace[ni][nj] = { { i,j }, idx };
			}
		}
	}

	if (dp[v][w] == 1e9)cout << 0;
	else {
		cout << dp[v][w] << endl;

		while (!(v == 0 && w == 0)) {
			cap[trace[v][w].Y]++;
			auto nxt = trace[v][w].X;
			v = nxt.X;
			w = nxt.Y;
		}

		FOR(i, 1, n)cout << cap[i] << ' ';
	}
}
