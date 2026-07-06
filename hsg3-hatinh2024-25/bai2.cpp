#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m, k, a[(int)1e5 + 5], b[(int)1e5 + 5];

bool ok(int x) {
	int i = 1, j = 1;
	int cnt = 0;
	while (i <= n && j <= m) {
		if (abs(a[i] - b[j]) <= x)cnt++, i++, j++;
		else {
			if (a[i] > b[j])j++;
			else i++;
		}
	}
	return cnt >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	cin >> n>>m>>k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= m; i++)cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);

	int l = 0, r = 1e9;
	int res = 1e9;
	while (l <= r) {
		int mid = l + r >> 1;
		if (ok(mid))res = min(res, mid), r = mid - 1;
		else l = mid + 1;
	}
	cout << res;
}
