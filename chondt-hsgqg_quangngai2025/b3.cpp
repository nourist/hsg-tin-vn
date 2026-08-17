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
int c[(int)1e5 + 5];
int l[(int)1e5 + 5];
vi adj[(int)1e5 + 5];
priority_queue<int>q[(int)1e5 + 5];
int sum[(int)1e5 + 5];
ll res = 0;

void dfs(int u) {
	for (int v : adj[u]) {
		dfs(v);
	}
	sort(all(adj[u]), [&](int x, int y) {
		return q[x].size() > q[y].size();
		});

	if (adj[u].size() >= 1) {
		swap(q[u], q[adj[u][0]]);
		swap(sum[u], sum[adj[u][0]]);
	}

	FOR(i, 1, (int)adj[u].size() - 1) {
		int v = adj[u][i];
		while (!q[v].empty()) {
			int nv = q[v].top();
			q[v].pop();

			q[u].push(nv);
			sum[u] += nv;

			while (!q[u].empty() && sum[u] > m) {
				sum[u] -= q[u].top();
				q[u].pop();
			}
		}
	}

	q[u].push(c[u]);
	sum[u] += c[u];
	while (!q[u].empty() && sum[u] > m) {
		sum[u] -= q[u].top();
		q[u].pop();
	}
	res = max(res, (ll)q[u].size() * l[u]);
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
	FOR(i, 1, n) {
		int p;
		cin >> p >> c[i] >> l[i];
		adj[p].pb(i);
	}

	dfs(adj[0][0]);
	cout << res;
}
