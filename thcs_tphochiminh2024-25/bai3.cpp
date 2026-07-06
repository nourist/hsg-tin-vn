#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5];
ll f[(int)1e5 + 5];

int bsearch(int u, int v) {
	ll res = 1e9;
	int l = u, r = v;
	while (l <= r) {
		int mid = (l + r) / 2;
		ll sum1 = f[mid] - f[u - 1];
		ll sum2 = f[v] - f[mid];
		res = min(res, abs(sum1 - sum2));
		if (sum1 > sum2) {
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, q, u, v;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	while (q--) {
		cin >> u >> v;
		cout << bsearch(u, v)<<'\n';
	}
}
