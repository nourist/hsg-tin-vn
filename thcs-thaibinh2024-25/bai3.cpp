#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e6 + 19];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n;
	cin >> n;
	ll res = -1e10, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		res = max(res, sum);
		if (sum < 0)sum = 0;
	}
	cout << res;
}
