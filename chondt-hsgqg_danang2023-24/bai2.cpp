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
#define Name "bai2"

int n, m, k, q;

struct Node {
	char f;
	int x, y;
}v[(int)2e5 + 5];

struct query {
	int x1, y1, x2, y2, v = 0, e = 0;
}queries[(int)2e5 + 5];

int bit[(int)2e5 + 5];

void clean() {
	memset(bit, 0, sizeof bit);
}

void update(int idx) {
	if (idx <= 0)return;
	for (idx; idx <= 2e5; idx += (idx & (-idx)))bit[idx]++;
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
	return res;
}

namespace queryV {
	struct QueryNode {
		int id, t, y, x1, x2, res;
	}qr[(int)4e5 + 5];

	vii nodes;

	void process() {
		clean();

		FOR(i, 1, k - 1) {
			nodes.push_back({ v[i].x, v[i].y });
			if (v[i].f == 'h')nodes.push_back({ v[i].x + 1,v[i].y });
			else nodes.push_back({ v[i].x,v[i].y + 1 });
		}

		sort(nodes.begin(), nodes.end());
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

		FOR(i, 1, q) {
			qr[i * 2 - 1] = { i,0,queries[i].y1 - 1 , queries[i].x1,queries[i].x2 };
			qr[i * 2] = { i,1,queries[i].y2, queries[i].x1,queries[i].x2 };
		}

		sort(qr + 1, qr + 2 * q + 1, [&](QueryNode x, QueryNode y) {
			return x.y < y.y;
			});

		sort(nodes.begin(), nodes.end(), [&](pii x, pii y) {
			return x.Y < y.Y;
			});

		int cur = 0;
		FOR(i, 1, q * 2) {
			while (cur < nodes.size() && nodes[cur].Y <= qr[i].y) {
				update(nodes[cur++].X);
			}

			qr[i].res = query(qr[i].x2) - query(qr[i].x1 - 1);
		}

		sort(qr + 1, qr + 2 * q + 1, [&](QueryNode x, QueryNode y) {
			if (x.id == y.id)return x.t < y.t;
			return x.id < y.id;
			});

		FOR(i, 1, q) {
			queries[i].v = qr[i * 2].res - qr[i * 2 - 1].res;
		}
	}
}

namespace queryEv {
	struct QueryNode {
		int id, t, y, x1, x2, res;
	}qr[(int)4e5 + 5];

	vii nodes;

	void process() {
		clean();

		FOR(i, 1, k - 1) {
			if (v[i].f == 'v')nodes.push_back({ v[i].x,v[i].y });
		}

		FOR(i, 1, q) {
			qr[i * 2 - 1] = { i,0,queries[i].y1 - 1 , queries[i].x1,queries[i].x2 };
			qr[i * 2] = { i,1,queries[i].y2 - 1, queries[i].x1,queries[i].x2 };
		}

		sort(qr + 1, qr + 2 * q + 1, [&](QueryNode x, QueryNode y) {
			return x.y < y.y;
			});

		sort(nodes.begin(), nodes.end(), [&](pii x, pii y) {
			return x.Y < y.Y;
			});

		int cur = 0;
		FOR(i, 1, q * 2) {
			while (cur < nodes.size() && nodes[cur].Y <= qr[i].y) {
				update(nodes[cur++].X);
			}

			qr[i].res = query(qr[i].x2) - query(qr[i].x1 - 1);
		}

		sort(qr + 1, qr + 2 * q + 1, [&](QueryNode x, QueryNode y) {
			if (x.id == y.id)return x.t < y.t;
			return x.id < y.id;
			});

		FOR(i, 1, q) {
			queries[i].e += qr[i * 2].res - qr[i * 2 - 1].res;
		}
	}
}

namespace queryEh {
	struct QueryNode {
		int id, t, x, y1, y2, res;
	}qr[(int)4e5 + 5];

	vii nodes;

	void process() {
		clean();

		FOR(i, 1, k - 1) {
			if (v[i].f == 'h')nodes.push_back({ v[i].x,v[i].y });
		}

		FOR(i, 1, q) {
			qr[i * 2 - 1] = { i,0,queries[i].x1 - 1 , queries[i].y1,queries[i].y2 };
			qr[i * 2] = { i,1,queries[i].x2 - 1, queries[i].y1,queries[i].y2 };
		}

		sort(qr + 1, qr + 2 * q + 1, [&](QueryNode x, QueryNode y) {
			return x.x < y.x;
			});

		sort(nodes.begin(), nodes.end(), [&](pii x, pii y) {
			return x.X < y.X;
			});

		int cur = 0;
		FOR(i, 1, q * 2) {
			while (cur < nodes.size() && nodes[cur].X <= qr[i].x) {
				update(nodes[cur++].Y);
			}

			qr[i].res = query(qr[i].y2) - query(qr[i].y1 - 1);
		}

		sort(qr + 1, qr + 2 * q + 1, [&](QueryNode x, QueryNode y) {
			if (x.id == y.id)return x.t < y.t;
			return x.id < y.id;
			});

		FOR(i, 1, q) {
			queries[i].e += qr[i * 2].res - qr[i * 2 - 1].res;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> k >> q;

	FOR(i, 1, k - 1) {
		cin >> v[i].f >> v[i].x >> v[i].y;
	}

	FOR(i, 1, q) {
		cin >> queries[i].x1 >> queries[i].y1 >> queries[i].x2 >> queries[i].y2;
	}

	queryV::process();
	queryEv::process();
	queryEh::process();

	FOR(i, 1, q) {
		// cout << queries[i].v << ' ' << queries[i].e << '\n';
		cout << queries[i].v - queries[i].e << '\n';
	}
}