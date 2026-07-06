#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long 
#define ld long double
#define X first
#define Y second
#define Name "post"

ll n, q;
ll a[(ll)3e5 + 5];
ll d[(ll)3e5 + 5];
vector<ll> p[(ll)3e5 + 5];
struct Query {
	ll l, r, id, res;
}query[(ll)3e5 + 5];
ll f[(ll)3e5 + 5];

void compress() {
	vector<ll> vals;
	FOR(i, 1, n) vals.push_back(a[i]);
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	FOR(i, 1, n) {
		a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
	}
}

void compresD() {
	vector<ll> vals;
	FOR(i, 0, n) vals.push_back(d[i]);
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	FOR(i, 0, n) {
		d[i] = lower_bound(vals.begin(), vals.end(), d[i]) - vals.begin() + 1;
	}
}

ll res = 0;

void add(ll pos) {
	res += f[pos];
	f[pos]++;
}

void remove(ll pos) {
	f[pos]--;
	res -= f[pos];
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
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

	FOR(i, 1, n) {
		p[a[i]].push_back(i);
	}

	FOR(i, 1, n) {
		if (p[i].size() <= 1) continue;
		ll sum = 0;
		FOR(j, 0, p[i].size() - 2) {
			ll s = rng();
			sum ^= s;
			d[p[i][j]] = s;
		}
		d[p[i].back()] = sum;
	}

	FOR(i, 1, n)d[i] ^= d[i - 1];

	compresD();

	FOR(i, 1, q) {
		ll l, r;
		cin >> l >> r;
		query[i] = { l, r, i, 0 };
	}

	const ll block = 550;
	sort(query + 1, query + q + 1, [](const Query& a, const Query& b) {
		if (a.l / block != b.l / block) return a.l / block < b.l / block;
		if (a.l / block % 2 == 0)return a.r < b.r;
		else return a.r > b.r;
		});

	add(d[0]);

	ll curL = 1, curR = 0;
	FOR(i, 1, q) {
		ll L = query[i].l;
		ll R = query[i].r;
		while (curR < R) {
			curR++;
			add(d[curR]);
		}
		while (curR > R) {
			remove(d[curR]);
			curR--;
		}
		while (curL < L) {
			remove(d[curL - 1]);
			curL++;
		}
		while (curL > L) {
			curL--;
			add(d[curL - 1]);
		}
		query[i].res = res;
	}

	sort(query + 1, query + q + 1, [](const Query& a, const Query& b) {
		return a.id < b.id;
		});

	FOR(i, 1, q)cout << query[i].res << "\n";
}
