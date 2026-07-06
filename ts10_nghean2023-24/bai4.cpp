#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m;
int a[(int)1e5 + 5], b[(int)1e5 + 5];

bool ok(int x) {
	for (int i = 1; i <= n; i++) {
		int l = a[i] - x;
		int r = a[i] + x;

		int it = upper_bound(b + 1, b + m + 1, r) - lower_bound(b + 1, b + m + 1, l);
		if (it == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> n >> m;

	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= m; i++)cin >> b[i];

	sort(b + 1, b + m + 1);

	int l = 0, r = 1e9;
	int res = 1e9;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(mid)) {
			res = min(res, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res;
}
