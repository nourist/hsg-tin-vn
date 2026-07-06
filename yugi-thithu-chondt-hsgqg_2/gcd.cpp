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
#define Name "gcd"

int p[(int)2e5 + 5];

vii factor(int n) {
	vii res;
	while (n != 1) {
		int cur = p[n];
		int cnt = 0;
		while (n % cur == 0) {
			n /= cur;
			cnt++;
		}
		res.pb({ cur, cnt });
	}
	sort(all(res));
	return res;
}

const ll mod = 1e9 + 7;

ll bpow(ll x, ll n) {
	if (n == 0)return 1;
	ll t = bpow(x, n / 2);
	if (n % 2 == 0)return t * t % mod;
	return t * t % mod * x % mod;
}

struct Node {
	vii ps;
	Node() {};
	Node(int n) : ps(factor(n)) {}
};

ostream& operator << (ostream& out, const Node& node) {
	ll res = 1;
	for (auto it : node.ps) {
		res = res * bpow(it.X, it.Y) % mod;
	}
	out << res;
	return out;
}

Node operator + (const Node& x, const Node& y) {
	Node res;
	int l = 0, r = 0;

	while (l < x.ps.size() && r < y.ps.size()) {
		if (x.ps[l].X == y.ps[r].X) {
			res.ps.pb({ x.ps[l].X, x.ps[l].Y + y.ps[r].Y });
			l++;
			r++;
		}
		else if (x.ps[l].X < y.ps[r].X) {
			res.ps.pb(x.ps[l]);
			l++;
		}
		else {
			res.ps.pb(y.ps[r]);
			r++;
		}
	}
	while (l < x.ps.size())res.ps.pb(x.ps[l++]);
	while (r < y.ps.size())res.ps.pb(y.ps[r++]);
	return res;
}

Node operator ^ (const Node& x, const Node& y) {
	Node res;
	int l = 0, r = 0;

	while (l < x.ps.size() && r < y.ps.size()) {
		if (x.ps[l].X == y.ps[r].X) {
			res.ps.pb({ x.ps[l].X, min(x.ps[l].Y, y.ps[r].Y) });
			l++;
			r++;
		}
		else if (x.ps[l].X < y.ps[r].X) {
			l++;
		}
		else {
			r++;
		}
	}
	return res;
}

int a[(int)2e5 + 5];
Node st[(int)8e5 + 5];

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = Node(a[l]);
		return;
	}

	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = st[id * 2] ^ st[id * 2 + 1];
}

void update(int id, int l, int r, int idx, int val) {
	if (idx<l || idx>r) {
		return;
	}
	if (l == r) {
		st[id] = st[id] + Node(val);
		return;
	}
	int mid = l + r >> 1;
	update(id * 2, l, mid, idx, val);
	update(id * 2 + 1, mid + 1, r, idx, val);
	st[id] = st[id * 2] ^ st[id * 2 + 1];
}

Node query(int id, int l, int r) {
	if (l == r)return st[id];

	int mid = l + r >> 1;
	return query(id * 2, l, mid) ^ query(id * 2 + 1, mid + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	FOR(i, 1, 2e5)p[i] = i;
	for (int i = 2; i * i <= 2e5; i++)
		if (p[i])for (int j = i * i; j <= 2e5; j += i)
			if (p[j] == j)p[j] = i;

	int n, q;
	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];

	build(1, 1, n);

	while (q--) {
		int i, x;
		cin >> i >> x;
		update(1, 1, n, i, x);
		cout << query(1, 1, n) << endl;
	}
}
