#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define X first 
#define Y second

int sz[(int)1e6 + 6], parent[(int)1e6 + 6];
int a[1003][1003];

int find_set(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find_set(parent[x]);
}

void union_set(int u, int v) {
	int x = find_set(u);
	int y = find_set(v);

	if (x != y) {
		parent[y] = x;
		sz[x] += sz[y];
	}
}

vector<pair<int, int>>steps = { {0,-1},{0,1},{1,0},{-1,0} };
int visited[1003][1003];
void bfs(pair<int,int>s) {
	if (visited[s.X][s.Y])return;

	deque<pair<int, int>>dq;
	dq.push_back(s);

	while (!dq.empty()) {
		pair<int, int>u = dq.front();
		dq.pop_front();

		if (visited[u.X][u.Y])continue;

		visited[u.X][u.Y] = 1;
		union_set(a[s.X][s.Y], a[u.X][u.Y]);

		for (pair<int, int>step : steps) {
			pair<int, int>v = { step.X + u.X, step.Y + u.Y };
			if (!visited[v.X][v.Y] && a[v.X][v.Y] != 0)dq.push_back(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			a[i][j] *= (i - 1) * m + j;
			if (a[i][j] != 0) {
				parent[a[i][j]] = a[i][j];
				sz[a[i][j]] = 1;
			}
			else {
				visited[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			bfs({ i,j });
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != 0)continue;
			set<int>side;
			for (pair<int, int>step : steps) {
				pair<int, int>v = { step.X + i, step.Y + j };
				if (a[v.X][v.Y] != 0)
					side.insert(find_set(a[v.X][v.Y]));
			}

			int sum = 1;
			for (int k : side)sum += sz[k];
			res = max(res, sum);
		}
	}
	cout << res;
}
