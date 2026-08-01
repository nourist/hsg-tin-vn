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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, m;
int p[(int)3e5 + 5];
vi adj[(int)3e5 + 5];
int dist[(int)3e5 + 5];
bool canVisit[(int)3e5 + 5];

pii dfs(int u, int par) {
	pii res = canVisit[u] ? make_pair(1, u) : make_pair((int)-1e9, 0);
	for (int v : adj[u]) {
		if (v == par)continue;
		auto it = dfs(v, u);
		res = max(res, { it.X + 1, it.Y });
	}
	return res;
}

bool ok(int mid) {
	int cnt = 0;
	FOR(i, 1, n) {
		canVisit[i] = dist[i] > mid;
		cnt += canVisit[i];
	}
	if (cnt <= 1) return true;

	// cout << mid << ' ' << dfs(dfs(1, 0).Y, 0).X / 2 << endl;

	return dfs(dfs(1, 0).Y, 0).X / 2 <= mid;
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
	FOR(i, 1, m)cin >> p[i];
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	FOR(i, 1, n)dist[i] = 1e9;
	queue<int>q;

	FOR(i, 1, m) {
		dist[p[i]] = 0;
		q.push(p[i]);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	// FOR(i, 1, n)cout << dist[i] << ' ';

	int l = 0, r = n, res = n;
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
	cout << res;
}
