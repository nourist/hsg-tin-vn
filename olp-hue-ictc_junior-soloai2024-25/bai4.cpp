#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m, k;
int a[(int)1e6 + 6];
int d[(int)1e6 + 6];
bool ban[(int)1e4][(int)1e4];

ll count(ll i, ll j) {
	if (n == 1) return 0;
	if (a[i] == a[j]) {
		ll s = (n - 1) / 2;
		if (n % 2 == 0) s++;
		return s;
	}
	ll tmp = abs(a[i] - a[j]) - 1, x = n - tmp - 2;
	if (tmp < x) swap(x, tmp);
	if (tmp <= 2 * x) return tmp;
	ll res = 2 * x;
	if (tmp & 1) res += (tmp - 2 * x) / 2 + 1;
	else res += (tmp - 2 * x) / 2;
	return min(tmp, res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= m * 2; i++)cin >> a[i];
	for (int u, v, i = 1; i <= k; i++)cin >> u >> v, ban[u][v]=ban[v][u]=1;

	sort(a + 1, a + m * 2 + 1);
	int res = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = m * 2; j > i; j++) {
			if (!ban[i][j] && !d[j]) {
				// int x = max(a[i], a[j]);
				// int y = min(a[i], a[j]);
				res += count(i,j);
				// cout << max(x - y - 1, y - 1 + n - x) << endl;
				d[j] = 1;
				break;
			}
		}
	}
	cout << res;
}