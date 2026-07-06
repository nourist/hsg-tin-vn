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
#define Name "THAMQUAN"

int n, m;
ll a[(int)1e5 + 5];
vi adj[(int)1e5 + 5];
vi sccAdj[(int)1e5 + 5];
int num[(int)1e5 + 5], low[(int)1e5 + 5];
int dfsTime = 0;
int scc[(int)1e5 + 5];
ll sccW[(int)1e5 + 5];
int sccCnt = 0;
bool in_stack[(int)1e5 + 5];

stack<int>st;

void dfs(int u) {
	num[u] = low[u] = ++dfsTime;
	in_stack[u] = 1;
	st.push(u);

	for (int v : adj[u]) {
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in_stack[v]) {
			low[u] = min(low[u], num[v]);
		}
	}

	if (low[u] == num[u]) {
		sccCnt++;
		while (!st.empty() && st.top() != u) {
			scc[st.top()] = sccCnt;
			in_stack[st.top()] = 0;
			sccW[sccCnt] += a[st.top()];
			st.pop();
		}
		scc[st.top()] = sccCnt;
		in_stack[st.top()] = 0;
		sccW[sccCnt] += a[st.top()];
		st.pop();
	}
}

ll dist[(int)1e5 + 5];

void finalDfs(int u) {
	if (dist[u] != -1)return;
	dist[u] = 0;
	for (int v : sccAdj[u]) {
		finalDfs(v);
		dist[u] = max(dist[u], dist[v]);
	}
	dist[u] += sccW[u];
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
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	FOR(i, 1, n)adj[0].pb(i);

	dfs(0);

	FOR(u, 0, n)for (int v : adj[u]) {
		if (scc[u] != scc[v])
			sccAdj[scc[u]].pb(scc[v]);
	}

	FOR(i, 1, sccCnt) {
		sort(sccAdj[i].begin(), sccAdj[i].end());
		sccAdj[i].erase(unique(sccAdj[i].begin(), sccAdj[i].end()), sccAdj[i].end());
	}

	FOR(i, 1, sccCnt)dist[i] = -1;

	finalDfs(scc[0]);

	cout << dist[scc[0]];
}
