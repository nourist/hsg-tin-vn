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

bool a[(int)1e3 + 3][(int)1e3 + 3];

bool ok(int i, int j) {
	if (!a[i][j]) {
		if (a[i - 1][j] && a[i][j - 1])return 1;
		if (a[i - 1][j] && a[i][j + 1])return 1;
		if (a[i + 1][j] && a[i][j - 1])return 1;
		if (a[i + 1][j] && a[i][j + 1])return 1;
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

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)FOR(j, 1, m) {
		char ch;
		cin >> ch;
		a[i][j] = ch == '.';
	}

	queue<pii>q;
	FOR(i, 1, n)FOR(j, 1, m)if (ok(i, j))q.push({ i,j });

	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		if (!ok(u.X, u.Y))continue;

		a[u.X][u.Y] = 1;

		FOR(sx, -1, 1)FOR(sy, -1, 1) {
			if (abs(sx) + abs(sy) == 0)continue;
			int nx = sx + u.X;
			int ny = sy + u.Y;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && ok(nx, ny))q.push({ nx, ny });
		}
	}
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			cout << (a[i][j] ? '.' : '#');
		}
		cout << endl;
	}
}
