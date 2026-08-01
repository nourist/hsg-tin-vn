#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
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
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b2"

int n, m;
bool a[2002][2002];
vii knight;
vii pawn;
int distK[2002][2002];
int distP[2002][2002];

int getKey(pii x) {
	return (x.X - 1) * m + x.Y;
}

vii steps[2] = { { {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
{-1, -2}, {-1, 2}, {1, -2}, {1, 2} },{{-1, 0}, {1, 0}, {0, -1}, {0, 1},
{-1, -1}, {-1, 1}, {1, -1}, {1, 1} } };

void bfs(pii s, int dist[], int T) {
	queue<pii>q;
	FOR(i, 1, n * m)dist[i] = 1e9;

	dist[getKey(s)] = 0;
	q.push(s);

	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		for (auto step : steps[T]) {
			int nx = u.X + step.X;
			int ny = u.Y + step.Y;

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] && dist[getKey({ nx, ny })] == 1e9) {
				dist[getKey({ nx, ny })] = dist[getKey(u)] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

bool ok(int s) {
	FOR(i, 2, knight.size()) {
		if (distK[i][s] % 2 != distK[i - 1][s] % 2)return 0;
	}
	return 1;
}

bool okS(pii u, int T) {
	for (auto step : steps[T]) {
		int nx = u.X + step.X;
		int ny = u.Y + step.Y;

		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny]) {
			return 1;
		}
	}
	return 0;
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
	FOR(i, 1, n)FOR(j, 1, m) {
		char ch;
		cin >> ch;
		if (ch == 'M') { knight.pb({ i, j }); }
		else if (ch == 'T') { pawn.pb({ i, j }); }
		if (ch != '#')a[i][j] = 1;
	}

	FOR(i, 1, knight.size())bfs(knight[i - 1], distK[i], 0);
	FOR(i, 1, pawn.size())bfs(pawn[i - 1], distP[i], 1);

	int res = 1e9;
	FOR(x, 1, n)FOR(y, 1, m) {
		if (!a[x][y])continue;

		int i = getKey({ x, y });
		if (!ok(i))continue;
		int mxK = 0;
		int mxP = 0;
		FOR(j, 1, knight.size())mxK = max(mxK, distK[j][i]);
		FOR(j, 1, pawn.size())mxP = max(mxP, distP[j][i]);

		if (mxK == 1e9 || mxP == 1e9)continue;

		int current_time = 0;

		if (knight.size() > 0 && pawn.size() > 0) {
			current_time = mxK;
			if (current_time < mxP) {
				current_time += (mxP + 1 - current_time) / 2 * 2;
			}
			if (current_time > 0 && !okS({ x, y }, 0)) continue;
			if (current_time > mxP && !okS({ x, y }, 1)) continue;
		}
		else if (knight.size() > 0) {
			current_time = mxK;
			if (current_time > 0 && !okS({ x, y }, 0)) continue;
		}
		else if (pawn.size() > 0) {
			current_time = mxP;
			if (current_time > 0 && !okS({ x, y }, 1)) continue;
		}

		res = min(res, current_time);
	}
	if (res == 1e9)cout << -1;
	else cout << res;
}
