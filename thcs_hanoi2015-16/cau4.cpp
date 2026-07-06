#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m, t, a[200][200];

bool ok(int i, int j) {
	if (a[i][j] == 0)return true;

	ll top = 1, down = 1, left = 1, right = 1;
	while (j - left >= 1 && a[i][j] == a[i][j - left])
		left++;
	while (j + right <= m && a[i][j] == a[i][j + right])
		right++;
	while (i - top >= 1 && a[i][j] == a[i - top][j])
		top++;
	while (i + down <= n && a[i][j] == a[i + down][j])
		down++;
	return max(right + left - 1, top + down - 1) >= t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res += !ok(i, j);
		}
	}
	cout << res;
}
