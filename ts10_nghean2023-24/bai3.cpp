#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[(int)1e6 + 6], a[(int)4e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int l = 0, r = 0;
	ll res = 0;
	while (r < n) {
		d[a[r]]++;
		while (d[a[r]] >= k) {
			res += n - r;
			d[a[l++]]--;
		}
		r++;
	}
	cout << res;
}
