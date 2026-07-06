#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "dulich"

int x[1003];

int timeDfs = 1, sccCnt = 0;
int num[1003], low[1003], scc[1003], sz[1003];
bool deleted[1003];
stack<int>st;

void dfs(int u) {
	num[u] = low[u] = timeDfs++;
	st.push(u);

	int v = x[u];
	if (u != v) {
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!deleted[v]) {
			low[u] = min(low[u], num[v]);
		}
	}

	if (low[u] == num[u]) {
		sccCnt++;
		while (1) {
			int v = st.top();
			st.pop();
			scc[v] = sccCnt;
			sz[sccCnt]++;
			deleted[v] = 1;
			if (v == u)break;
		}
	}
}

bool dp[1003][1003]; //n, k
bool newdp[1003][1003];

vi adj[1003];

void dp_dfs(int u) {
	dp[u][0] = dp[u][sz[u]] = 1;

	for (int v : adj[u]) {
		dp_dfs(v);

		memset(newdp[u], 0, sizeof newdp[u]);

		FOR(i, 0, sz[u]) {
			if (!dp[u][i])continue;

			newdp[u][i] = 1;

			if (i == 0 && u != 0) continue;

			FOR(j, 0, sz[v]) {
				if (!dp[v][j])continue;

				newdp[u][i + j] = 1;
			}
		}

		FOR(i, 0, 1000)dp[u][i] = newdp[u][i];

		sz[u] += sz[v];
	}
}

int in_degree[1003];

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
	FOR(i, 1, n) {
		cin >> x[i];
	}

	FOR(i, 1, n)if (!num[i])dfs(i);
	FOR(u, 1, n) {
		int v = x[u];

		if (scc[u] == scc[v])continue;

		adj[scc[v]].pb(scc[u]);
		in_degree[scc[u]]++;
	}

	FOR(i, 1, sccCnt) {
		if (in_degree[i] == 0)adj[0].pb(i);
	}

	FOR(i, 1, sccCnt) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}

	dp_dfs(0);
	int res = 0;
	FOR(i, 0, k)if (dp[0][i])res = max(res, i);
	cout << res;
}
