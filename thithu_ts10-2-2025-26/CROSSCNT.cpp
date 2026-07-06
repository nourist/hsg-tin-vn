#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int d[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("CROSSCNT.inp", "r")) {
		freopen("CROSSCNT.inp", "r", stdin);
		freopen("CROSSCNT.out", "w", stdout);
	}

	// for (int i = 1; i * i <= 1e6; i++) {
	// 	for (int j = i; j <= 1e6; j += i) {
	// 		d[j]++;
	// 		if (i * i != j)d[j]++;
	// 	}
	// }

	for (int i = 1; i <= 1e6; i++) {
		for (int j = i; j <= 1e6; j += i) {
			d[j]++;
		}
	}

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	FOR(i, 1, n) FOR(j, 1, m)
		cin >> a[i][j], a[i][j] = d[a[i][j]];

	vector<vector<int>> top(n + 1, vector<int>(m + 1, 1)), bottom(n + 1, vector<int>(m + 1, 1)), left(n + 1, vector<int>(m + 1, 1)), right(n + 1, vector<int>(m + 1, 1));
	FOR(i, 1, n)FOR(j, 1, m) {
		if (i > 1 && a[i][j] == a[i - 1][j])top[i][j] = top[i - 1][j] + 1;
		if (j > 1 && a[i][j] == a[i][j - 1])left[i][j] = left[i][j - 1] + 1;
	}
	FOD(i, n, 1)FOD(j, m, 1) {
		if (i < n && a[i][j] == a[i + 1][j])bottom[i][j] = bottom[i + 1][j] + 1;
		if (j < m && a[i][j] == a[i][j + 1])right[i][j] = right[i][j + 1] + 1;
	}

	int res = 0;
	FOR(i, 1, n)FOR(j, 1, m)res += min({ top[i][j], bottom[i][j], left[i][j], right[i][j] }) - 1;
	cout << res;
}
