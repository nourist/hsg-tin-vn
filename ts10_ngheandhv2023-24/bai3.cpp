#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m;
ll a[110][1111];
ll d[2222];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin>>n>>m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	ll mi = 1e10, ma = -1e10;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			memset(d, 0, sizeof d);
			int l = 1, r = 1;
			int idx = 1;
			while (l <= m && r <= m) {
				if (a[i][l] > a[j][r]) {
					d[idx++] = a[j][r++];
				}
				else {
					d[idx++] = a[i][l++];
				}
			}
			while (l <= m) {
				d[idx++] = a[i][l++];
			}
			while (r <= m) {
				d[idx++] = a[j][r++];
			}
			mi = min(d[m], mi);
			ma = max(d[m], ma);
		}
	}
	cout << mi << ' ' << ma;
}
