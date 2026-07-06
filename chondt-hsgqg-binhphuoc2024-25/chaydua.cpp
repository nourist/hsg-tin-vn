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
#define Name "chaydua"

int dist1[303][303];
int dist2[303][303];
bool edges[303][303];

int n, m;

void floyd(int dist[303][303]) {
	FOR(c, 1, n)FOR(u, 1, n)FOR(v, 1, n) {
		if (dist[u][c] + dist[c][v] < dist[u][v]) {
			dist[u][v] = dist[u][c] + dist[c][v];
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

	FOR(i, 1, n)FOR(j, 1, n)dist1[i][j] = dist2[i][j] = 1e9;

	FOR(i, 1, m) {
		int u, v, r, t;
		cin >> u >> v >> r >> t;

		dist1[u][v] = 1;
		dist2[u][v] = r - t;
		edges[u][v] = 1;
	}

	floyd(dist1);
	floyd(dist2);

	int len = 1e9;
	FOR(u, 1, n)FOR(v, 1, n) {
		if (u == v)continue;

		if (edges[u][v] && dist1[v][u] != 1e9) {
			len = min(len, dist1[v][u] + 1);
		}
	}

	int cnt = 0;
	FOR(u, 1, n)FOR(v, 1, n) {
		if (u == v)continue;

		if (edges[u][v] && dist1[v][u] != 1e9 && dist1[v][u] + 1 == len) {
			cnt++;
		}
	}

	cout << cnt << ' ' << len << endl;
}
