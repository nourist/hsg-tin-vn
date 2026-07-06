#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "tet"

const int block = 750;
int n, q;
int a[(int)2e5 + 5];
struct Query {
	int l, r, id;
	ll res;
}query[(int)4e5 + 5];
int block_id[(int)4e5 + 5];
int f[(int)2e5 + 5];

void compress() {
	vector<int> v;
	FOR(i, 1, n) v.push_back(a[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	FOR(i, 1, n) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

ll res = 0;

inline void add(int pos) {
	res += f[pos];
	f[pos]++;
}

inline void remove(int pos) {
	f[pos]--;
	res -= f[pos];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> q;

	FOR(i, 1, n) cin >> a[i];

	compress();

	set<int> v = { 0,n + 1 };
	FOR(i, 1, q) {
		int p;
		cin >> p;
		auto it = upper_bound(v.begin(), v.end(), p);
		query[i].r = *it - 1;
		query[i].l = *(--it) + 1;
		query[i].id = i;
		v.insert(p);
	}

	int j = q + 1;
	for (auto it = ++v.begin(); it != v.end(); it++) {
		auto prev = it; prev--;
		query[j].l = *prev + 1;
		query[j].r = *it - 1;
		query[j].id = j;
		j++;
	}

	FOR(i, 1, q * 2 + 1)
		block_id[i] = query[i].l / block;

	sort(query + 1, query + q * 2 + 2, [](const Query& a, const Query& b) {
		if (block_id[a.id] != block_id[b.id])
			return block_id[a.id] < block_id[b.id];
		if (block_id[a.id] & 1)
			return a.r > b.r;
		return a.r < b.r;
		});

	int curL = 1, curR = 0;
	FOR(i, 1, q * 2 + 1) {
		int L = query[i].l;
		int R = query[i].r;
		while (curR < R) {
			curR++;
			add(a[curR]);
		}
		while (curR > R) {
			remove(a[curR]);
			curR--;
		}
		while (curL < L) {
			remove(a[curL]);
			curL++;
		}
		while (curL > L) {
			curL--;
			add(a[curL]);
		}
		query[i].res = 1LL * (R - L + 1) * (R - L) / 2 - res + 1;
	}

	sort(query + 1, query + q * 2 + 2, [](const Query& a, const Query& b) {
		return a.id < b.id;
		});

	FOD(i, q * 2 + 1, 1)
		query[i].res = max(query[i].res, query[i + 1].res);
	FOR(i, 2, q + 1)cout << query[i].res << "\n";
}