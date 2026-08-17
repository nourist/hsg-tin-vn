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
#define Name "game"

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

int u[(int)1e5 + 5];
int v[(int)1e5 + 5];
int s[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m, d, k;
	cin >> n >> m >> d >> k;

	vector<vi> a(n + 2, vi(m + 2, -1));
	vector<vi> D(n + 2, vi(m + 2, 0));

	FOR(i, 1, k) {
		cin >> u[i] >> v[i] >> s[i];
		a[u[i]][v[i]] = s[i];
	}

	FOR(i, 1, n)FOR(j, 1, m) {
		if (a[i][j] == -1) {
			continue;
		}

		D[i][j] = (a[i][j] - D[i - 1][j] + d) % d;
	}

	FOR(i, 1, k) {
		cout << 0 << ' ' << D[u[i] - 1][v[i]] << ' ' << 0 << ' ' << D[u[i]][v[i]] << endl;
	}
}