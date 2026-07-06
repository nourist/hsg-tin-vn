#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll n, q;
ll a[(ll)2e5 + 5], b[(ll)2e5 + 5];
ll hashCode[(ll)4e5 + 5];

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

void compress() {
	map<ll, ll>mp;
	FOR(i, 1, n) {
		mp[a[i]] = 1;
		mp[b[i]] = 1;
	}

	ll cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->second = cnt++;
	}

	FOR(i, 1, n) {
		a[i] = mp[a[i]];
		b[i] = mp[b[i]];
	}
}

void genHashCode() {
	FOR(i, 1, 4e5) {
		hashCode[i] = rd();
	}
}

struct Query {
	ll l, r, id, res;
};

struct BIT {
	ll bit[(ll)2e5 + 5];

	void update(ll idx, ll v) {
		for (idx; idx <= 2e5; idx += (idx & (-idx))) {
			bit[idx] ^= v;
		}
	}

	ll query(ll idx) {
		ll res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx))) {
			res ^= bit[idx];
		}
		return res;
	}
};

struct QueryHandler {
	Query qr[(ll)2e5 + 5];
	BIT bit;
	ll arr[(ll)2e5 + 5];
	ll last_pos[(ll)2e5 + 5];

	void solve() {
		sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
			return x.r < y.r;
			});

		ll idx = 1;
		FOR(i, 1, q) {
			while (idx <= qr[i].r) {
				bit.update(idx, hashCode[arr[idx]]);
				if (last_pos[arr[idx]])
					bit.update(last_pos[arr[idx]], hashCode[arr[idx]]);
				last_pos[arr[idx]] = idx;
				idx++;
			}

			qr[i].res = bit.query(qr[i].r) ^ bit.query(qr[i].l - 1);
		}

		sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
			return x.id < y.id;
			});
	}
}qrA, qrB;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("ECO.inp", "r")) {
		freopen("ECO.inp", "r", stdin);
		freopen("ECO.out", "w", stdout);
	}

	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> b[i];

	compress();
	genHashCode();

	FOR(i, 1, n)qrA.arr[i] = a[i];
	FOR(i, 1, n)qrB.arr[i] = b[i];

	FOR(i, 1, q) {
		ll l, r, x, y;
		cin >> l >> r >> x >> y;

		qrA.qr[i].id = i;
		qrA.qr[i].l = l;
		qrA.qr[i].r = r;

		qrB.qr[i].id = i;
		qrB.qr[i].l = x;
		qrB.qr[i].r = y;
	}

	qrA.solve();
	qrB.solve();

	FOR(i, 1, q) {
		if (qrA.qr[i].res == qrB.qr[i].res) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}
