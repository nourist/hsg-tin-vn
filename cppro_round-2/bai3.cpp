#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool special[256];

struct CharCounter {
	int f[256];
	int cnt = 0;

	void add(int x) {
		if (!special[x])return;

		if (f[x] == 0)cnt++;
		f[x]++;
	}

	void rem(int x) {
		if (!special[x])return;

		if (f[x] == 1)cnt--;
		f[x]--;
	}
}d1, d2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, k, l, r;
	string s, t;

	cin >> n >> k >> l >> r >> s >> t;

	s = "_" + s;

	for (auto i : t)special[i] = 1;

	int L1 = 1, L2 = 1, R = 1;
	ll res = 0;

	while (R <= n) {
		d1.add(s[R]);
		d2.add(s[R]);

		while (d1.cnt > r) { //d1.cnt <= r, L1 MAX
			d1.rem(s[L1++]);
		}

		bool des = d2.cnt >= l;
		while (d2.cnt >= l && L2 <= R) { //d2.cnt >= l, L2 min
			d2.rem(s[L2++]);
		}
		if (des)
			d2.add(s[--L2]);

		if (d1.cnt <= r && d1.cnt >= l && d2.cnt <= r && d2.cnt >= l) {
			res += L2 - L1 + 1;
			// cerr << R << ' ' << L2 - L1 + 1 << endl;
		}
		// else
		// 	cerr << R << ' ' << 0 << endl;

		R++;
	}
	cout << res;
}

/*
6 3 2 3
abacbc
abc

*/