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
#define Name "b3"

const ll mod = 1e9 + 7;
ll cal[(int)1e6 + 6];
ll inv[(int)1e6 + 6];
int f[(int)1e6 + 6];

pii range[(int)1e6 + 6];
vi adj[(int)1e6 + 6];

ll dfs(int u) {
	ll s = range[u].Y - range[u].X - 1;
	ll res = 1;
	for (int v : adj[u]) {
		res = res * dfs(v) % mod;
		s -= range[v].Y - range[v].X + 1;
	}
	res = res * cal[s / 2] % mod;
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

	inv[1] = 1;
	FOR(i, 2, 1e6 + 1)inv[i] = mod - mod / i * inv[mod % i] % mod;
	cal[0] = 1;
	FOR(i, 1, 1e6)cal[i] = cal[i - 1] * 2 * (2 * i - 1) % mod * inv[i + 1] % mod;

	int n, m;
	cin >> n >> m;

	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}

	range[0] = { 0, n + 1 };
	FOR(i, 1, m) {
		cin >> range[i].X >> range[i].Y;
		if ((range[i].Y - range[i].X - 1) % 2 == 1) {
			cout << 0;
			return 0;
		}
		f[range[i].X]++;
		f[range[i].Y]++;
	}

	FOR(i, 1, n)if (f[i] > 1) {
		cout << 0;
		return 0;
	}

	sort(range + 1, range + m + 1, [&](pii x, pii y) {
		return x.Y < y.Y;
		});

	stack<int>st;
	FOR(i, 1, m) {
		while (!st.empty() && range[st.top()].X > range[i].X) {
			adj[i].pb(st.top());
			st.pop();
		}
		if (!st.empty() && range[st.top()].Y >= range[i].X) {
			cout << 0;
			return 0;
		}
		st.push(i);
	}
	while (!st.empty()) {
		adj[0].pb(st.top());
		st.pop();
	}
	cout << dfs(0);
}
