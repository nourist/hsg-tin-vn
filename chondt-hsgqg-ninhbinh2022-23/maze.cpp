#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second

int n, m;
int a[1505][1505];
int bfsTime[1505][1505];
int dist[1505][1505];

vector<pii>steps = { {1,0},{-1, 0},{0,1},{0,-1} };

void preBfs() {
	queue<pii>q;
	FOR(i, 1, n)FOR(j, 1, m)if (a[i][j] == 'S') { q.push({ i,j }); bfsTime[i][j] = 1; }

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		int i = cur.X, j = cur.Y;

		for (auto step : steps) {
			int newI = step.X + i;
			int newJ = step.Y + j;

			if (newI<1 || newI>n || newJ<1 || newJ>m)continue;
			if (a[newI][newJ] == 'X')continue;
			if (bfsTime[newI][newJ] != 0)continue;

			bfsTime[newI][newJ] = bfsTime[i][j] + 1;
			q.push({ newI, newJ });
		}
	}
}

void bfs() {
	queue<pii>q;
	FOR(i, 1, n)FOR(j, 1, m)if (a[i][j] == 'E') { q.push({ i,j }); dist[i][j] = 1; }

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		int i = cur.X, j = cur.Y;

		for (auto step : steps) {
			int newI = step.X + i;
			int newJ = step.Y + j;

			if (newI<1 || newI>n || newJ<1 || newJ>m)continue;
			if (a[newI][newJ] == 'X' || a[newI][newJ] == 'S')continue;
			if (dist[newI][newJ] != 0)continue;
			if (bfsTime[newI][newJ] != 0 && dist[i][j] + 1 >= bfsTime[newI][newJ])continue;

			dist[newI][newJ] = dist[i][j] + 1;
			q.push({ newI, newJ });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("maze.inp", "r")) {
		freopen("maze.inp", "r", stdin);
		freopen("maze.out", "w", stdout);
	}

	cin >> n >> m;

	FOR(i, 1, n) {
		string t;
		cin >> t;
		FOR(j, 1, t.size()) {
			a[i][j] = t[j - 1];
		}
	}

	preBfs();
	bfs();

	int res = 1e9;
	FOR(i, 1, n)FOR(j, 1, m)if ((i == 1 || i == n || j == 1 || j == m) && dist[i][j] != 0)res = min(res, dist[i][j]);

	if (res == 1e9)cout << -1;
	else cout << res;
}
