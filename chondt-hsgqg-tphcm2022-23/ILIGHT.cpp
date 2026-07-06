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
#define Name "ILIGHT"

int n, k;
struct Node {
	int x, y, id;
} a[(int)2e5 + 5];
pii ar[(int)2e5 + 5];
int t[(int)2e5 + 5];
pii t2[(int)2e5 + 5];

void compress() {
	map<int, int>mp;
	FOR(i, 1, n)mp[a[i].x] = mp[a[i].y] = 1;
	FOR(i, 1, k)mp[t2[i].X] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->Y = cnt++;
	}

	FOR(i, 1, n) {
		a[i].x = mp[a[i].x];
		a[i].y = mp[a[i].y];
	}

	FOR(i, 1, k)t2[i].X = mp[t2[i].X];
	FOR(i, 1, k)t[i] = mp[t[i]];
}

struct Query {
	int id, res, s, t;
}qr[(int)2e5 + 5];

namespace countBit {
	int bit[(int)6e5 + 5];

	void update(int idx) {
		if (idx == 0)return;
		for (idx; idx <= 6e5; idx += (idx & (-idx)))bit[idx]++;
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}
};

namespace maxBit {
	int bit[(int)6e5 + 5];

	void update(int idx, int v) {
		if (idx == 0)return;
		for (idx; idx <= 6e5; idx += (idx & (-idx)))bit[idx] = max(bit[idx], v);
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res = max(res, bit[idx]);
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;

	FOR(i, 1, n) {
		cin >> a[i].x >> a[i].y;

		a[i].id = i;
		ar[i].X = a[i].x;
		ar[i].Y = a[i].y;

		if (a[i].x > a[i].y)
			swap(a[i].x, a[i].y);

	}

	FOR(i, 1, k)cin >> t[i];
	FOR(i, 1, k)t2[i].X = t[i];
	FOR(i, 1, k)t2[i].Y = i;

	compress();

	sort(a + 1, a + n + 1, [&](Node x, Node y) {
		return x.y < y.y;
		});

	sort(t2 + 1, t2 + k + 1);

	// FOR(i, 1, n)cout << a[i].y << ' ';
	// cout << endl;

	int cur = 1;
	FOR(i, 1, n) {
		while (cur <= k && t2[cur].X < a[i].y) {
			maxBit::update(6e5 - t2[cur].X, t2[cur].Y);
			cur++;
		}
		qr[i].id = a[i].id;
		int pos = maxBit::query(6e5 - a[i].x);
		if (pos == 0) {
			qr[i].t = 0;
			qr[i].s = pos;
		}
		else {
			qr[i].t = 1;
			qr[i].s = pos;
		}
	}

	sort(qr + 1, qr + n + 1, [&](Query x, Query y) {
		return x.s > y.s;
		});

	// FOR(i, 1, n)cout << qr[i].s << ' ';
	// cout << endl;

	sort(a + 1, a + n + 1, [&](Node x, Node y) {
		return x.id < y.id;
		});

	cur = k;
	FOR(i, 1, n) {
		while (cur > qr[i].s) {
			countBit::update(t[cur]);
			cur--;
		}
		int cnt = countBit::query(6e5) - countBit::query(a[qr[i].id].x - 1);

		if (qr[i].t == 0) {
			if (cnt % 2 == 0)qr[i].res = ar[qr[i].id].X;
			else qr[i].res = ar[qr[i].id].Y;
		}
		else {
			int l = min(ar[qr[i].id].Y, ar[qr[i].id].X);
			int r = max(ar[qr[i].id].Y, ar[qr[i].id].X);

			if (cnt % 2 == 0)qr[i].res = r;
			else qr[i].res = l;
		}
	}

	ll res = 0;
	FOR(i, 1, n)res += qr[i].res;
	cout << res;
}
