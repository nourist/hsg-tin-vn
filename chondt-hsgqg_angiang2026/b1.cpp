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
#define Name "b1"

int n, m, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> q;
	vector<vi>f(n + 2, vector<int>(m + 2, 0));

	while (q--) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		f[x][y]++;
		f[x][v + 1]--;
		f[u + 1][y]--;
		f[u + 1][v + 1]++;
	}

	FOR(i, 1, n)FOR(j, 1, m)f[i][j] += f[i - 1][j];
	FOR(i, 1, n)FOR(j, 1, m)f[i][j] += f[i][j - 1];

	int res = 0;
	FOR(i, 1, n)FOR(j, 1, m)res += f[i][j] % 2;
	cout << res;
}
