#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 5];
ll f[(int)1e5 + 5];

int solve(int l, int r) {
	if (r == l)
		return 0;

	ll sum = f[r] - f[l - 1];

	if (sum % 2 == 1){
		return 0;
	}

	ll midSum = sum / 2;

	int mid = lower_bound(f + l, f + r + 1, f[l - 1] + midSum) - f;

	if (f[mid] != f[l-1]+midSum) {
		return 0;
	}

	return max(solve(l, mid), solve(mid + 1, r)) + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("seq10.inp", "r")) {
		freopen("seq10.inp", "r", stdin);
		freopen("seq10.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	cout << solve(1, n);
}
