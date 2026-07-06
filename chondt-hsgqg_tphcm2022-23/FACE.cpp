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
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MARK(x, i) ((x) | (1LL << (i)))
#define UNMARK(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "face"

ll f[(int)1e3 + 3][(int)1e3 + 3];

ll get(ll x, ll y, ll u, ll v) {
	x += 1;
	y += 1;
	u += 1;
	v += 1;
	return f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, t;
	cin >> n >> t;

	FOR(i, 1, n)FOR(j, 1, n)cin >> f[j][i];

	FOR(i, 1, n)FOR(j, 1, n)f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];

	while (t--) {
		int x[6], y[6];
		FOR(i, 1, 4)cin >> x[i] >> y[i];

		// cout << get(x[3], y[3], x[4], y[4]) << ' ' << get(x[1], y[1], x[2], y[2]) << endl;

		cout << -(get(x[3], y[3], x[4], y[4]) - get(x[1], y[1], x[2], y[2])) << '\n';
	}
}