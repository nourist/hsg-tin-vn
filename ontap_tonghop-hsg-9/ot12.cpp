#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 8], b[(int)1e6 + 8];
int n, m, ta, tb, k;

bool ok() {
	if (k >= n)return 0;
	for (int i = k - 1; i < n; i++) {
		if (lower_bound(b, b + m, a[i] + ta) != b + m)return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("VANCHUYEN.inp", "r", stdin);
	freopen("VANCHUYEN.out", "w", stdout);


	cin >> n >> m >> ta >> tb >> k;

	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];

	int res = -1;
	for (int i = 0; i < n; i++) {
		if (i <= k) {
			int l = k - i;
			res = max(res, b[min(m - 1, (int)(lower_bound(b, b + m, a[i] + ta) - b) + l)] + tb);
		}
	}
	if (ok())
		cout << res;
	else cout << -1;
}
