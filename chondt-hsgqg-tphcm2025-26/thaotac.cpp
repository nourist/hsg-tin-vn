#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

const int block = 2e2;
int n, q;
int a[(int)5e4 + 4];

struct Query {
	ll id, l, r, res;
}qr[(int)1e5 + 5];

namespace sub13 {
	ll res = 0;
	void addR(int l, int r, int delta) {
		FOR(i, l, r - 1) {
			res += delta * (a[i] % a[r]);
		}
	}

	void addL(int l, int r, int delta) {
		FOR(i, l + 1, r) {
			res += delta * (a[l] % a[i]);
		}
	}

	void solve() {
		int l = 1, r = 0;
		FOR(i, 1, q) {
			while (r < qr[i].r) {
				r++;
				addR(l, r, 1);
			}
			while (r > qr[i].r) {
				addR(l, r, -1);
				r--;
			}
			while (l < qr[i].l) {
				addL(l, r, -1);
				l++;
			}
			while (l > qr[i].l) {
				l--;
				addL(l, r, 1);
			}
			qr[i].res = res;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("thaotac.inp", "r")) {
		freopen("thaotac.inp", "r", stdin);
		freopen("thaotac.out", "w", stdout);
	}

	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, q) {
		cin >> qr[i].l >> qr[i].r;
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		if (x.r / block != y.r / block)return x.r / block < y.r / block;
		if ((x.r / block) % 2 == 0) {
			return x.l < y.l;
		}
		else {
			return x.l > y.l;
		}
		});


	if (n <= 1e3)
		sub13::solve();
	else
		sub24::solve();

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		return x.id < y.id;
		});

	FOR(i, 1, q)cout << qr[i].res << '\n';
}
