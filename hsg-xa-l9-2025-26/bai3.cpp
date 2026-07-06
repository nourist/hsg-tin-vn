#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, q, x, t;
	cin >> n >> q;

	ll sum = 0, cntc = 0, cntl = 0;
	FOR(i, 1, n) {
		cin >> x;
		sum += x;
		if (x % 2 == 0) cntc++;
		else cntl++;
	}

	while (q--) {
		cin >> t >> x;
		if (t == 0) {
			sum += cntc * x;
			if (x % 2 == 1) {
				cntl += cntc;
				cntc = 0;
			}
		}
		else {
			sum += cntl * x;
			if (x % 2 == 1) {
				cntc += cntl;
				cntl = 0;
			}
		}
		cout << sum << "\n";
	}
}
