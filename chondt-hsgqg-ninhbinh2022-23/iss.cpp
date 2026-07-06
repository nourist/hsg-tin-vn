#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll a[(int)1e5 + 5], w[(int)1e5 + 5];
ll bit[(int)1e5 + 5];

void update(int i, ll v) {
	for (i; i <= 1e5; i += (i & (-i))) {
		bit[i] = max(bit[i], v);
	}
}

ll query(int i) {
	ll res = 0;
	for (i; i > 0; i -= (i & (-i))) {
		res = max(res, bit[i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("iss.inp", "r")) {
		freopen("iss.inp", "r", stdin);
		freopen("iss.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> w[i];

	FOR(i, 1, n) {
		update(a[i], query(a[i] - 1) + w[i]);
	}

	cout << query(1e5);
}
