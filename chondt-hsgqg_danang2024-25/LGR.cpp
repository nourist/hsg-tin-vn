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
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "lgr"

vi adj[(int)1e5 + 5];

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

	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	FOR(i, 1, n)sort(adj[i].begin(), adj[i].end());

	ll res = 0;

	FOR(u, 1, n) {
		auto itL = lower_bound(adj[u].begin(), adj[u].end(), u);
		int l = itL == adj[u].begin() ? 0 : *(--itL);

		auto itR = upper_bound(adj[u].begin(), adj[u].end(), u);
		int r = itR == adj[u].end() ? n + 1 : *(itR);

		res += 1LL * (r - u) * (u - l);

		if (l != 0) {
			auto itL2 = lower_bound(adj[l].begin(), adj[l].end(), l);
			int l2 = itL2 == adj[l].begin() ? 0 : *(--itL2);
			res += 1LL * (r - u) * (l - l2);
		}
	}

	cout << res;
}