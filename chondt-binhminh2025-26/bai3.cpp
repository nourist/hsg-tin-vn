#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, a[(int)1e6 + 6], f[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		f[a[i]]++;
	}

	int maxx = -1;
	FOD(i, 1e6, 1) {
		if (f[i] >= 2) {
			if (maxx == -1) {
				maxx = i;
			}
			else {
				cout << (maxx + i) * 2;
				return 0;
			}
		}
		if (f[i] >= 4) {
			cout << i * 4;
			return 0;
		}
	}
	cout << -1;
}
