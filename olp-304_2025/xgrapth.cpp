#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll inf = 1e15;
ll n, m, q;
struct node {
	ll s, c;
}a[(ll)1e5 + 5];
vector<pair<ll, ll>>adj[(ll)1e5 + 5];
struct query {
	ll id, l, h, r, res;
}queries[(ll)1e5 + 5];
ll dist[(ll)1e5 + 5];
vector<pair<ll, ll>>path;
ll st[(ll)12e5 + 6];

void stupdate(ll id, ll l, ll r, ll i, ll v) {
	if (i<l || i>r)return;
	if (l == r) {
		st[id] = v;
		return;
	}

	ll mid = (l + r) / 2;
	stupdate(id * 2, l, mid, i, v);
	stupdate(id * 2 + 1, mid + 1, r, i, v);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

ll stquery(ll id, ll l, ll r, ll u, ll v) {
	if (v<l || u>r)return inf;
	if (u <= l && v >= r)return st[id];

	ll mid = (l + r) / 2;
	return min(
		stquery(id * 2, l, mid, u, v),
		stquery(id * 2 + 1, mid + 1, r, u, v)
	);
}

void init() {
	cin >> n >> m >> q;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].c;
	}

	for (ll u, v, w, i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	for (ll i = 1; i <= q; i++) {
		cin >> queries[i].l >> queries[i].h >> queries[i].r;
		queries[i].id = i;
	}

	sort(queries + 1, queries + q + 1, [&](query x, query y) {
		return x.r < y.r;
		});
}

void dijkstra() {
	for (ll i = 2; i <= n; i++)dist[i] = inf;

	priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
	q.push({ 0,1 });

	while (!q.empty()) {
		pair<ll, ll>top = q.top();
		q.pop();
		ll kc = top.first;
		ll u = top.second;

		if (kc > dist[u])continue;

		for (auto it : adj[u]) {
			ll v = it.first;
			ll w = it.second;

			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.push({ dist[v], v });
			}
		}
	}
}

void minimize() {
	map<ll, ll>mp;

	for (ll i = 1; i <= n; i++)mp[a[i].s] = 1;
	for (ll i = 1; i <= q; i++)mp[queries[i].l] = 1, mp[queries[i].h] = 1;

	ll order = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->second = order++;

	for (ll i = 1; i <= n; i++)a[i].s = mp[a[i].s];
	for (ll i = 1; i <= q; i++)queries[i].l = mp[queries[i].l], queries[i].h = mp[queries[i].h];
}

void solve() {
	fill(st, st + (ll)1e6, inf);

	for (ll i = 1; i <= n; i++)path.push_back({ dist[i], i });
	sort(path.begin(), path.end());

	ll idx = 0;
	for (ll i = 1; i <= q; i++) {
		while (idx < path.size() && path[idx].first <= queries[i].r) {
			stupdate(1, 1, 3e5, a[path[idx].second].s, a[path[idx].second].c);
			idx++;
		}

		queries[i].res = stquery(1, 1, 3e5, queries[i].l, queries[i].h);
		if (queries[i].res == inf)queries[i].res = -1;
	}
}

void output() {
	sort(queries + 1, queries + q + 1, [&](query x, query y) {
		return x.id < y.id;
		});

	for (ll i = 1; i <= q; i++)cout << queries[i].res << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("xgrapth.inp", "r")) {
		freopen("xgrapth.inp", "r", stdin);
		freopen("xgrapth.out", "w", stdout);
	}

	init();
	dijkstra();
	minimize();
	solve();
	output();
}
