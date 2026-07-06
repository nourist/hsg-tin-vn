#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, m;
int a[808][808];
bool visited[808][808];

void dfs(int i, int j, int k) {
	if (visited[i][j])return;

	visited[i][j] = 1;

	FOR(xi, -1, 1)FOR(xj, -1, 1) {
		if (abs(xi) + abs(xj) == 1) {
			int newi = i + xi;
			int newj = j + xj;

			if (newi >= 1 && newi <= n && newj >= 1 && newj <= m && abs(a[i][j] - a[newi][newj]) <= k) {
				dfs(newi, newj, k);
			}
		}
	}
}

bool ok(int k) {
	FOR(i, 1, n)FOR(j, 1, m)visited[i][j] = 0;
	dfs(1, 1, k);
	return visited[n][m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("robot.inp", "r")) {
		freopen("robot.inp", "r", stdin);
		freopen("robot.out", "w", stdout);
	}

	cin >> n >> m;
	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];

	int res = 1e6, l = 0, r = 1e6;
	while (l <= r) {
		int mid = (l + r) / 2;
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
