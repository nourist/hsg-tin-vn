#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)3e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dp_c7.inp", "r")) {
		freopen("dp_c7.inp", "r", stdin);
		freopen("dp_c7.out", "w", stdout);
	}

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++)cin >> a[i];

	int sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum < 0)sum = 0;
		res = max(res, sum);
	}
	cout << res * x;
}