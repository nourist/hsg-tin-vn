#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 5], d[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i];
	}

	ll prev = 0, res = -1e9;
	for (int i = 1; i <= n; i++) {
		res = max(res, d[i] - prev);
		prev = min(prev, d[i]);
	}
	cout << res;
}
