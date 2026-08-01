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
#define Name "PLANT"

int st[(int)4e5 + 5];
int lazy[(int)4e5 + 5];

void fix(int id, int l, int r) {
	if (lazy[id] == -1)return;
	st[id] = lazy[id] * (r - l + 1);
	if (l != r) {
		lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
	}
	lazy[id] = -1;
}

void update(int id, int l, int r, int u, int v, int val) {
	if (r<u || l>v)return;

	fix(id, l, r);

	if (u <= l && r <= v) {
		lazy[id] = val;
		fix(id, l, r);
		return;
	}

	int mid = l + r >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int id, int l, int r, int u, int v) {
	if (r<u || l>v)return 0;

	fix(id, l, r);

	if (u <= l && r <= v) {
		return st[id];
	}

	int mid = l + r >> 1;
	return 	query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

vi adj[(int)1e5 + 5];
char opr[(int)1e5 + 5];
int U[(int)1e5 + 5];
int n = 1;
int St[(int)1e5 + 5];
int En[(int)1e5 + 5];
int timeDfs = 0;

void dfs(int u) {
	St[u] = ++timeDfs;
	for (int v : adj[u]) {
		dfs(v);
	}
	En[u] = timeDfs;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	FOR(i, 1, 4e5)lazy[i] = -1;

	int q;
	cin >> q;

	FOR(i, 1, q) {
		cin >> opr[i] >> U[i];
		if (opr[i] == '+') {
			adj[U[i]].pb(n);
			n++;
		}
	}

	dfs(0);

	update(1, 1, n, 1, 1, 1);
	int cnt = 1;
	FOR(i, 1, q) {
		if (opr[i] == '+') {
			update(1, 1, n, St[cnt], St[cnt], 1);
			cnt++;
		}
		else if (opr[i] == '-') {
			update(1, 1, n, St[U[i]], En[U[i]], 0);
		}
		else {
			cout << query(1, 1, n, St[U[i]], En[U[i]]) << endl;
		}
	}
}
