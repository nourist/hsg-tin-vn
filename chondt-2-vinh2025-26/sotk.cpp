#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, m, k;
int a[(int)1e5 + 5], b[(int)1e5 + 5];

bool ok(int x) {
	int j = m, cnt = 0;
	FOR(i, 1, n) {
		if (a[i] + b[1] > x)break;
		while (j > 0 && a[i] + b[j] > x)j--;
		cnt += j;
		if (cnt >= k)return 1;
	}
	return cnt >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("sotk.inp", "r")) {
		freopen("sotk.inp", "r", stdin);
		freopen("sotk.out", "w", stdout);
	}

	cin >> n >> m >> k;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m)cin >> b[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);

	int l = a[1] + b[1], r = a[n] + b[m], res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
}
