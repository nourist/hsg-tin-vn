#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, d, k;
int a[(int)2e5 + 5];
int st[20][(int)2e5 + 5];

void preprocess() {
	FOR(i, 1, n)st[0][i] = a[i];

	FOR(k, 1, 17) {
		for (int i = 1; i + (1 << k) - 1 <= n; i++) {
			st[k][i] = __gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		}
	}
}

int query(int l, int r) {
	int k = __lg(r - l + 1);
	return __gcd(st[k][l], st[k][r - (1 << k) + 1]);
}

bool ok(int mid) {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	cin >> n >> d >> k;
	FOR(i, 1, n)cin >> a[i];

	preprocess();

	int l = 1, r = n, res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res;
}
