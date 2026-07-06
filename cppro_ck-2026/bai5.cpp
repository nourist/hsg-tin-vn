#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

namespace sub1 {
	void solve() {
		int q, n;
		cin >> q;
		while (q--) {
			cin >> n;

			ll res = 0;
			FOR(i, 0, n) {
				res++;
				FOR(d, 1, n - i) {
					res += (n - i) / d;
				}
			}
			cout << res << endl;
		}
	}
}

namespace sub2 {
	void solve() {
		int q, n;
		cin >> q;
		while (q--) {
			cin >> n;

			ll res = n + 1;
			FOR(d, 1, n) {
				// FOR(i, 0, n) {
				// 	res += i / d;
				// }
				res += (n / d - 1) * (n / d) / 2 * d + (n - (n / d - 1) * d) * (n / d);
			}
			cout << res << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	sub2::solve();

}
