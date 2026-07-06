#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e6 + 6];
int l1[(int)1e6 + 6], l2[(int)1e6 + 6], r1[(int)1e6 + 6], r2[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n) {
		if (a[i] % 2 == 0) {
			l1[i]++;
			r1[i]++;
		}
		else {
			l2[i]++;
			r2[i]++;
		}
	}

	FOR(i, 1, n)l1[i] += l1[i - 1];
	FOR(i, 1, n)l2[i] += l2[i - 1];
	FOD(i, n, 1)r1[i] += r1[i + 1];
	FOD(i, n, 1)r2[i] += r2[i + 1];

	FOR(i, 2, n - 1) {
		if (l1[i - 1] == r1[i + 1] || l2[i - 1] == r2[i + 1]) {
			cout << i - 1;
			return 0;
		}
	}
	cout << -1;
}
