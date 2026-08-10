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
#define Name "b3"

int n, m;
pair<int, pii>edges[(int)2e5 + 5];
vii adj[(int)1e5 + 5];
int sccCnt = 0;
int low[(int)1e5 + 5];
int num[(int)1e5 + 5];
int timeDfs = 0;
stack<int>st;
bool deleted[(int)1e5 + 5];
bool used[(int)2e5 + 5];

void dfs(int u) {
	num[u] = low[u] = ++timeDfs;
	st.push(u);
	for (auto e : adj[u]) {
		int v = e.X;
		int id = e.Y;
		if (used[id])continue;
		used[id] = 1;
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
			deleted[v] = 1;
			if (v == u)break;
		}
	}
}

bool ok(int mid) {
	sccCnt = 0;
	timeDfs = 0;
	memset(used, 0, sizeof used);
	memset(low, 0, sizeof low);
	memset(num, 0, sizeof num);
	memset(deleted, 0, sizeof deleted);
	while (!st.empty())st.pop();
	FOR(i, 1, n) {
		adj[i].clear();
	}
	FOR(i, 1, mid) {
		adj[edges[i].Y.X].pb({ edges[i].Y.Y, i });
		adj[edges[i].Y.Y].pb({ edges[i].Y.X, i });
	}

	FOR(i, 1, n)if (!num[i])dfs(i);

	return sccCnt == 1;
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
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = { w, {u, v} };
	}

	sort(edges + 1, edges + m + 1);

	int l = 0, r = m, res = m + 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	if (res == m + 1)cout << -1;
	else cout << edges[res].X;
}
