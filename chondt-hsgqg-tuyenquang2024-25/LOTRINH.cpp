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
#define Name "lotrinh"

int n, m, k, x;
vii adjA1[(int)1e5 + 5];
vii adjAn[(int)1e5 + 5];
vii adjB[(int)1e5 + 5];
int dist1[(int)1e5 + 5];
int dist2[(int)1e5 + 5];
int dist3[(int)1e5 + 5];

void dijkstra(vii adj[], int dist[], int s) {
	FOR(i, 1, n)dist[i] = 1e9;
	priority_queue<pii, vii, greater<pii>>q;

	dist[s] = 0;
	q.push({ 0, s });

	while (!q.empty()) {
		auto from = q.top();
		q.pop();

		int d = from.X;
		int u = from.Y;

		if (d > dist[u])continue;

		for (auto to : adj[u]) {
			int v = to.X;
			int w = to.Y;

			if (d + w < dist[v]) {
				dist[v] = d + w;
				q.push({ dist[v], v });
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

	cin >> n >> m >> k >> x;
	FOR(i, 1, m) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		adjA1[u].push_back({ v, b });
		adjAn[v].push_back({ u, b });
		adjB[v].push_back({ u, a });
	}

	dijkstra(adjA1, dist1, 1);
	dijkstra(adjAn, dist2, n);
	dijkstra(adjB, dist3, k);

	int res = 1e9;
	FOR(i, 1, n) {
		if (dist1[i] + dist3[i] <= x) {
			res = min(res, dist1[i] + dist2[i]);
		}
	}
	if (res == 1e9)cout << -1;
	else cout << res;
}