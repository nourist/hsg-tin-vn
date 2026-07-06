#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define int long long
#define ld long double
#define pii pair<int,int>
#define X first
#define Y second

const int maxN = 1e5 + 5;
int n, q;
struct Gift {
	int w, s;
}v[maxN];

struct Node {
	vector<Gift>vals;
	vector<int>f, sum, preCnt;
}st[(int)4 * maxN];

Node mergeNode(Node a, Node b) {
	int i = 0, j = 0;
	Node res;
	while (i < a.vals.size() && j < b.vals.size()) {
		if (a.vals[i].s < b.vals[j].s) {
			res.vals.push_back(a.vals[i]);
			++i;
		}
		else {
			res.vals.push_back(b.vals[j]);
			++j;
		}
	}
	while (i < a.vals.size()) {
		res.vals.push_back(a.vals[i]);
		++i;
	}
	while (j < b.vals.size()) {
		res.vals.push_back(b.vals[j]);
		++j;
	}
	res.f.resize(res.vals.size(), 0);
	res.sum.resize(res.vals.size(), 0);
	res.preCnt.resize(res.vals.size(), 0);
	FOR(i, 0, res.vals.size() - 1) {
		res.f[i] = res.vals[i].w;
		res.preCnt[i] = res.vals[i].s;
		res.sum[i] = res.vals[i].s * res.vals[i].w;
	}
	FOR(i, 1, res.vals.size() - 1) {
		res.f[i] += res.f[i - 1];
		res.preCnt[i] += res.preCnt[i - 1];
		res.sum[i] += res.sum[i - 1];
	}
	return res;
}

Node newNode(Gift val) {
	Node res;
	res.vals.push_back(val);
	res.f.push_back(val.w);
	res.preCnt.push_back(val.s);
	res.sum.push_back(val.s * val.w);
	return res;
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = newNode(v[l]);
		return;
	}

	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	st[id] = mergeNode(st[id << 1], st[id << 1 | 1]);
}

pii queryNode(int id, int t) {
	int it = upper_bound(st[id].vals.begin(), st[id].vals.end(), Gift{ 0, t }, [](const Gift& a, const Gift& b) {
		return a.s < b.s;
		}) - st[id].vals.begin() - 1;

	if (it == -1) {
		return { st[id].vals.size() * t, st[id].f.back() * t };
	}

	return { st[id].preCnt[it] + (st[id].vals.size() - it - 1) * t, st[id].sum[it] + (st[id].f.back() - st[id].f[it]) * t };
}

int queryTree(int id, int l, int r, int t, int k, int sum = 0, int cnt = 0) {
	if (l == r) {
		int need = k * t - cnt;
		if (need > v[l].s) return 1e9;
		return sum + need * v[l].w;
	}

	int mid = (l + r) >> 1;
	pii qr1 = queryNode(id * 2, t);

	if (cnt + qr1.X <= k * t) {
		cnt += qr1.X;
		sum += qr1.Y;
		return queryTree(id * 2 + 1, mid + 1, r, t, k, sum, cnt);
	}
	else {
		return queryTree(id * 2, l, mid, t, k, sum, cnt);
	}
}

bool query1(int m, int k, int t) {
	int total = queryTree(1, 1, n, t, k);
	return total <= m;
}

int query2(int m, int k) {
	int l = 0, r = 1e9, res = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (query1(m, k, mid)) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("gift.inp", "r")) {
		freopen("gift.inp", "r", stdin);
		freopen("gift.out", "w", stdout);
	}

	cin >> n >> q;
	FOR(i, 1, n)cin >> v[i].w;
	FOR(i, 1, n)cin >> v[i].s;

	sort(v + 1, v + n + 1, [](const Gift& a, const Gift& b) {
		return a.w < b.w;
		});

	build(1, 1, n);

	while (q--) {
		int te, m, k, t;
		cin >> te;
		if (te == 1) {
			cin >> m >> k >> t;
			cout << query1(m, k, t) << "\n";
		}
		else {
			cin >> m >> k;
			cout << query2(m, k) << "\n";
		}
	}
}
