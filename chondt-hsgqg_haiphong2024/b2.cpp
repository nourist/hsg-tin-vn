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
#define Name "b2"

int u[404 * 404], v[404 * 404];
int dp[404][404];
bool a[404][404];
int res[404 * 404];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m, k;
	cin >> n >> m >> k;
	FOR(i, 1, k)cin >> u[i] >> v[i];

	memset(a, 1, sizeof a);
	FOR(i, 1, k)a[u[i]][v[i]] = 0;

	int cur = 0;

	FOR(i, 1, n)FOR(j, 1, m) {
		int newdp = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
		if (a[i][j]) {
			dp[i][j] = newdp;
			cur = max(cur, newdp);
		}
	}

	FOD(i, k, 1) {
		res[i] = cur * cur;

		a[u[i]][v[i]] = 1;
		int newdp = min({ dp[u[i] - 1][v[i] - 1], dp[u[i] - 1][v[i]], dp[u[i]][v[i] - 1] }) + 1;
		cur = max(cur, newdp);

		if (dp[u[i]][v[i]] != newdp) {
			dp[u[i]][v[i]] = newdp;
			queue<pii>q;
			q.push({ u[i], v[i] });
			while (!q.empty()) {
				auto from = q.front();
				q.pop();
				int x = from.X, y = from.Y;

				FOR(sx, 0, 1)FOR(sy, 0, 1) {
					if (sx + sy == 0)continue;

					int nx = x + sx;
					int ny = y + sy;

					int ndp = min({ dp[nx - 1][ny - 1], dp[nx - 1][ny], dp[nx][ny - 1] }) + 1;

					if (nx <= n && ny <= m && a[nx][ny] != 0 && dp[nx][ny] != ndp) {
						cur = max(cur, ndp);
						dp[nx][ny] = ndp;
						q.push({ nx, ny });
					}
				}
			}
		}
	}

	FOR(i, 1, k)cout << res[i] << endl;
}
