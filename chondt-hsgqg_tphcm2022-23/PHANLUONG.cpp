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
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "PHANLUONG"

int n, m, k;
vii adj[(int)2e5 + 5];
pii edges[(int)2e5 + 5];
int x[(int)2e5 + 5];
int y[(int)2e5 + 5];

namespace twoCC {
	int num[(int)2e5 + 5];
	int low[(int)2e5 + 5];

	int dfsTime = 1;

	stack<int>st;

	int ecc[(int)2e5 + 5];
	int cnt = 0;

	vi bridges;

	void dfs(int u, int par = -1) {
		num[u] = low[u] = dfsTime++;
		st.push(u);

		for (auto to : adj[u]) {
			int v = to.X;
			int id = to.Y;

			if (id == par)continue;

			if (!num[v]) {
				dfs(v, id);
				low[u] = min(low[u], low[v]);
			}
			else {
				low[u] = min(low[u], num[v]);
			}
		}

		if (num[u] == low[u]) {
			cnt++;
			while (1) {
				int v = st.top();
				st.pop();

				ecc[v] = cnt;

				if (v == u)break;
			}

			if (par != -1) {
				bridges.push_back(par);
			}
		}
	}

	vii treeAdj[(int)2e5 + 5];

	void process() {
		FOR(i, 1, n)if (!num[i])dfs(i);

		for (auto i : bridges) {
			auto e = edges[i];

			int u = twoCC::ecc[e.X];
			int v = twoCC::ecc[e.Y];

			treeAdj[u].push_back({ v, i });
			treeAdj[v].push_back({ u, i });
		}
	}
};

namespace lca {
	int up[(int)2e5 + 5][20];
	int depth[(int)2e5 + 5];

	void dfs(int u, int par) {
		for (auto to : twoCC::treeAdj[u]) {
			int v = to.X;
			if (v == par)continue;

			up[v][0] = u;
			depth[v] = depth[u] + 1;

			dfs(v, u);
		}
	}

	void preprocess() {
		FOR(i, 1, twoCC::cnt)if (!up[i][0]) {
			depth[i] = 1;
			dfs(i, 0);
		}

		FOR(k, 1, 16) {
			FOR(i, 1, twoCC::cnt) {
				up[i][k] = up[up[i][k - 1]][k - 1];
			}
		}
	}

	int lca(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);

		FOD(k, 16, 0) {
			if (depth[v] - depth[u] >= (1 << k)) {
				v = up[v][k];
			}
		}

		if (u == v)return u;

		FOD(k, 16, 0) {
			if (up[v][k] != up[u][k]) {
				v = up[v][k];
				u = up[u][k];
			}
		}
		return up[u][0];
	}
}

namespace solve {
	int fUp[(int)2e5 + 5];
	int fDown[(int)2e5 + 5];
	int res[(int)2e5 + 5];

	bool visited[(int)2e5 + 5];

	void dfs(int u, int par) {
		visited[u] = 1;

		for (auto to : twoCC::treeAdj[u]) {
			int v = to.X;
			int id = to.Y;

			if (v == par)continue;
			dfs(v, u);

			fUp[u] += fUp[v];
			fDown[u] += fDown[v];

			if (fUp[v] > 0) {
				if (twoCC::ecc[edges[id].X] == v)res[id] = 'P';
				else res[id] = 'T';
			}
			else if (fDown[v] > 0) {
				if (twoCC::ecc[edges[id].X] == u)res[id] = 'P';
				else res[id] = 'T';
			}
		}
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

	cin >> n >> m;
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({ v,i });
		adj[v].push_back({ u,i });
		edges[i] = { u,v };
	}
	cin >> k;
	FOR(i, 1, k)cin >> x[i] >> y[i];

	twoCC::process();

	lca::preprocess();

	FOR(i, 1, k) {
		int u = twoCC::ecc[x[i]];
		int v = twoCC::ecc[y[i]];

		if (u == v)continue;

		int g = lca::lca(u, v);

		solve::fUp[u]++;
		solve::fUp[g]--;
		solve::fDown[v]++;
		solve::fDown[g]--;
	}

	FOR(i, 1, twoCC::cnt)if (!solve::visited[i])
		solve::dfs(i, 0);

	FOR(i, 1, m) {
		if (!solve::res[i])cout << 'X';
		else cout << (char)solve::res[i];
	}
}