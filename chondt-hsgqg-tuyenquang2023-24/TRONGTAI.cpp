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
#define Name "TRONGTAI"

vii adj[(int)1e4 + 4];
int dist[(int)1e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m, x, y;
	cin >> n >> m >> x >> y;

	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	dist[x] = 1e9;

	priority_queue<pii, vii>q;
	q.push({ 1e9, x });

	while (!q.empty()) {
		auto from = q.top();
		q.pop();

		int d = from.X;
		int u = from.Y;

		if (d < dist[u])continue;

		for (auto to : adj[u]) {
			int v = to.X;
			int w = to.Y;

			if (min(d, w) > dist[v]) {
				dist[v] = min(d, w);
				q.push({ dist[v], v });
			}
		}
	}

	cout << dist[y];
}