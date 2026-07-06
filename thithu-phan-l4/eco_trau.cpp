#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define ll long long
using ull = unsigned long long;

ll n, q;
ll a[(ll)2e5 + 5], b[(ll)2e5 + 5];
ull hashCode[(ll)4e5 + 5];

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

void compress() {
	map<ll, ll> mp;
	FOR(i, 1, n) {
		mp[a[i]] = 1;
		mp[b[i]] = 1;
	}

	ll cnt = 1;
	for (auto& it : mp) it.second = cnt++;

	FOR(i, 1, n) {
		a[i] = mp[a[i]];
		b[i] = mp[b[i]];
	}
}

void genHashCode() {
	FOR(i, 1, 4e5) hashCode[i] = rd();
}

struct Query {
	ll l, r, id;
	ull res;
};

struct BIT {
	ull bit[(ll)2e5 + 5];

	void update(ll idx, ull v) {
		for (; idx <= n; idx += idx & -idx) {
			bit[idx] += v;
		}
	}

	ull query(ll idx) {
		ull res = 0;
		for (; idx > 0; idx -= idx & -idx) {
			res += bit[idx];
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
		sort(qr + 1, qr + q + 1, [](Query a, Query b) {
			return a.r < b.r;
			});

		ll idx = 1;
		FOR(i, 1, q) {
			while (idx <= qr[i].r) {
				ll x = arr[idx];

				// thêm tại idx
				bit.update(idx, hashCode[x]);

				// xóa lần trước
				if (last_pos[x])
					bit.update(last_pos[x], -hashCode[x]);

				last_pos[x] = idx;
				idx++;
			}

			qr[i].res = bit.query(qr[i].r) - bit.query(qr[i].l - 1);
		}

		sort(qr + 1, qr + q + 1, [](Query a, Query b) {
			return a.id < b.id;
			});
	}
} qrA, qrB;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	if (fopen("eco.inp", "r")) {
		freopen("eco.inp", "r", stdin);
		freopen("eco.ans", "w", stdout);
	}


	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];

	compress();
	genHashCode();

	FOR(i, 1, n) qrA.arr[i] = a[i];
	FOR(i, 1, n) qrB.arr[i] = b[i];

	FOR(i, 1, q) {
		ll l, r, x, y;
		cin >> l >> r >> x >> y;

		qrA.qr[i] = { l, r, i, 0 };
		qrB.qr[i] = { x, y, i, 0 };
	}

	qrA.solve();
	qrB.solve();

	FOR(i, 1, q) {
		if (qrA.qr[i].res == qrB.qr[i].res) cout << "YES\n";
		else cout << "NO\n";
	}
}