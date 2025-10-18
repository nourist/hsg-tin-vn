#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e7 + 7];
int d[(int)2e6 + 6];
int f[(int)2e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; ++i)cin >> a[i], ++d[max(0, a[i] - x)], --d[a[i] + x + 1], ++f[a[i]];
	for (int i = 1; i <= 1e6; ++i) {
		d[i] += d[i - 1];
	}
	ll res = 0;
	for (int i = 0; i <= 1e6; ++i) {
		res += 1LL*f[i] * (d[i] - 1);
	}
	cout << (res >> 1);
}
