#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m, s, t;
vector<pair<int, int>>adj[(int)1e5 + 5];

bool p[(int)2e6 + 6];
int rp[(int)2e6 + 6];

void sieve() {
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 2e6; i++)
		if (p[i])
			for (int j = i * i; j <= 2e6; j += i)
				p[j] = 0;

	for (int i = 2e6; i >= 0; i--)
		if (p[i])
			rp[i] = i;
		else
			rp[i] = rp[i + 1];
}

void init() {
	cin >> n >> m >> s >> t;

	for (int u, v, w, i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, rp[w]-w });
		adj[v].push_back({ u, rp[w]-w });
	}
}

void dijkstra() {
	vector<ll>d(n + 1, 1e11);
	d[s] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>q;

	q.push({ 0,s });

	while (!q.empty()) {
		pair<ll, int>top = q.top();
		q.pop();

		int u = top.second;
		ll distance = top.first;

		if (distance > d[u])continue;

		for (pair<ll, int> i : adj[u]) {
			int v = i.first;
			ll w = i.second;
			if (d[v] > d[u] + w) {
				d[v] = min(d[v], d[u] + w);
				q.push({ d[v], v });
			}
		}
	}
	cout << (d[t] == 1e11 ? -1 : d[t]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	sieve();
	init();
	dijkstra();
}
