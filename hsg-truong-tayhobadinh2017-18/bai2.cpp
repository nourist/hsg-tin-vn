#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, a[(int)5e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	int res = 0;
	sort(a + 1, a + n + 1);
	FOR(i, 1, n)FOR(j, i + 1, n) {
		int l = a[j] - a[i];
		int r = a[i] + a[j];

		res += lower_bound(a + j + 1, a + n + 1, r) - upper_bound(a + j + 1, a + n + 1, l);
	}
	cout << res;
}
