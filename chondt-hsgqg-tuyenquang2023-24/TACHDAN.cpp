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
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "TACHDAN"

ll n, k, h;
vi adj[(int)1e5 + 5];
ll a[(int)1e5 + 5];
ll f1[(int)1e5 + 5];
ll f2[(int)1e5 + 5];

int res = 0;

void dfs(int u, int par) {
	f1[u] = 1;
	f2[u] = a[u];

	for (int v : adj[u]) {
		dfs(v, u);
		f1[u] += f1[v];
		f2[u] += f2[v];
	}

	if (u != 1 && f1[u] >= k && f2[u] >= h)res++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k >> h;

	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	dfs(1, 0);

	cout << res;
}