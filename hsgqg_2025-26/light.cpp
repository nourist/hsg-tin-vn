#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>

const int M = 6, N = 666, INF = 1e9 + 7;
int n, q, x, y;
int a[N + 6], f[N + 6][3];
int dp[M + 1][N + 6][N + 6];

struct State {
	int c0, c1, c2;
};

struct Move { int x1, x2, x0, y0, y1, y2; };

void preprocess() {
	vector<Move>moves;

	FOR(x0, 0, 5)FOR(x1, 0, 5)FOR(x2, 0, 5)FOR(y0, 0, 5)FOR(y1, 0, 5)FOR(y2, 0, 5) {
		if (x0 + x1 + x2 != x)continue;
		if (y0 + y1 + y2 != y)continue;

		moves.push_back({ x0, x1, x2, y0, y1, y2 });
	}

	FOR(c0, 0, M)FOR(c1, 0, N)FOR(c2, 0, N) {
		dp[c0][c1][c2] = INF;
	}

	queue<State>q;
	FOR(c0, 0, M) {
		dp[c0][0][0] = 0;
		q.push({ c0,0,0 });
	}

	while (!q.empty()) {
		State u = q.front(); q.pop();
		int cur = dp[u.c0][u.c1][u.c2];

		for (auto& m : moves) {
			if (u.c0 < m.x0 + m.y0)continue;
			if (u.c1 < m.x1 + m.y1)continue;
			if (u.c2 < m.x2 + m.y2)continue;

			int nc0 = u.c0 - m.x0 - m.y0 + m.y2 + m.x1;
			int nc1 = u.c1 - m.x1 - m.y1 + m.y0 + m.x2;
			int nc2 = u.c2 - m.x2 - m.y2 + m.y1 + m.x0;

			if (nc0 > M)nc0 = M;
			if (nc1 > N)continue;
			if (nc2 > N)continue;

			if (dp[nc0][nc1][nc2] > cur + 1) {
				dp[nc0][nc1][nc2] = cur + 1;
				q.push({ nc0, nc1, nc2 });
			}
		}
	}

	FOR(c0, 0, M)FOR(c1, 0, N)FOR(c2, 0, N) {
		if (dp[c0][c1][c2] == INF)dp[c0][c1][c2] = -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("light.inp", "r")) {
		freopen("light.inp", "r", stdin);
		freopen("light.out", "w", stdout);
	}

	cin >> n >> q >> x >> y;
	FOR(i, 1, n) {
		cin >> a[i];
		FOR(j, 0, 2) {
			f[i][j] = f[i - 1][j];
		}
		f[i][a[i]]++;
	}

	preprocess();

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << dp[min(M, f[r][0] - f[l - 1][0])][f[r][1] - f[l - 1][1]][f[r][2] - f[l - 1][2]] << '\n';
	}
}
