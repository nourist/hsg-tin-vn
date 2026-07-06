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
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "KIMCUONG"

int n, m;
int a[2002][2002];
int up[2002][2002], down[2002][2002];
int diaDL[2002][2002], diaDR[2002][2002], diaUL[2002][2002], diaUR[2002][2002];
int cc[2002][2002];
int sz[4000044];

int dfs(int id, int x, int y) {
	if (a[x][y] || cc[x][y] != 0)return 0;

	cc[x][y] = id;

	int res = 1;
	FOR(sx, -1, 1)FOR(sy, -1, 1) {
		if (abs(sx) + abs(sy) != 1)continue;

		int nx = x + sx;
		int ny = y + sy;

		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			res += dfs(id, nx, ny);
	}
	return res;
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

	FOR(i, 1, n) {
		string s;
		cin >> s;
		FOR(j, 1, m) {
			a[i][j] = s[j - 1] == '#';
		}
	}

	int cnt = 1;
	FOR(i, 1, n)FOR(j, 1, m) {
		if (cc[i][j] == 0) {
			sz[cnt] = dfs(cnt, i, j);
			cnt++;
		}
	}

	FOR(i, 1, n)FOR(j, 1, m) {
		if (!a[i][j])up[i][j] = up[i - 1][j] + 1;
	}
	FOD(i, n, 1)FOR(j, 1, m) {
		if (!a[i][j])down[i][j] = down[i + 1][j] + 1;
	}

	FOD(i, n, 1)FOR(j, 1, m) {
		if (a[i][j])diaDL[i][j] = diaDL[i + 1][j - 1] + 1;
	}
	FOD(i, n, 1)FOD(j, m, 1) {
		if (a[i][j])diaDR[i][j] = diaDR[i + 1][j + 1] + 1;
	}
	FOR(i, 1, n)FOD(j, m, 1) {
		if (a[i][j])diaUR[i][j] = diaUR[i - 1][j + 1] + 1;
	}
	FOR(i, 1, n)FOR(j, 1, m) {
		if (a[i][j])diaUL[i][j] = diaUL[i - 1][j - 1] + 1;
	}

	int res = 0;
	FOR(i, 1, n)FOR(j, 1, m) {
		if (up[i][j] == 0 || down[i][j] == 0 || up[i][j] != down[i][j])continue;

		int l = up[i][j];

		int top = i - l;
		int bot = i + l;

		int cnt = l * (l - 1) / 2 * 4 + 1;

		res += min({ diaDL[top][j], diaDR[top][j], diaUL[bot][j], diaUR[bot][j] }) >= up[i][j] + 1 && cnt == sz[cc[i][j]];
	}
	cout << res;
}