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

int dp[404][404];
pii to[404];
pair<pii, int>trace[404][404];
bool used[404];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		to[u] = { v, i };
		to[v] = { u + n * 2, i };
		to[u + n * 2] = { v + n * 2, i };
	}

	FOR(len, 1, n * 2) {
		FOR(i, 1, n * 4 - len + 1) {
			int j = i + len - 1;

			dp[i][j] = dp[i + 1][j];
			trace[i][j] = { {i + 1,j},0 };

			int v = to[i].X;
			if (v > i && v <= j) {
				int newVal = dp[v + 1][j] + 1;
				if (newVal > dp[i][j]) {
					dp[i][j] = newVal;
					trace[i][j] = { {v + 1, j}, to[i].Y };
				}
			}
		}
	}

	int res = 0;
	FOR(i, 1, n * 2) {
		res = max(res, dp[i][i + n * 2 - 1]);
	}
	cout << res << endl;

	int u, v;
	FOR(i, 1, n * 2) {
		if (dp[i][i + n * 2 - 1] == res) {
			u = i;
			v = i + n * 2 - 1;
		}
	}

	while (u != v) {
		used[trace[u][v].Y] = 1;
		pii nxt = trace[u][v].X;
		u = nxt.X;
		v = nxt.Y;
	}

	FOR(i, 1, n)if (used[i])cout << i << ' ';
}