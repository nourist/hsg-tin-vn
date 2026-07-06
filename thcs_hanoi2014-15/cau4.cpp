#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[200][200];
bool d[200][200];

vector<pair<int, int>>steps = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1,1} };

int spread(int x, int y) {
	if (!d[x][y])return 0;

	deque<pair<int, int>>q;
	int res = 1;
	q.push_back({ x,y });
	d[x][y] = 0;

	while (!q.empty()) {
		auto stand = q.front();
		for (auto step : steps) {
			if (d[stand.first + step.first][stand.second + step.second] && a[stand.first][stand.second] == a[stand.first + step.first][stand.second + step.second]) {
				res++;
				d[stand.first + step.first][stand.second + step.second] = 0;
				q.push_back({ stand.first + step.first , stand.second + step.second });
			}
		}
		q.pop_front();
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			d[i][j] = 1;
		}
	}

	int cnt = 0, mx = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int res = spread(i, j);
			if (res >= 2)cnt++;
			mx = max(mx, res);
		}
	}
	cout << cnt << endl << mx;
}
