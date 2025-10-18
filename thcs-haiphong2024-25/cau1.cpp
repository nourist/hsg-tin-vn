#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool ok(int n) {
	n *= 2;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
		int j = n / i;
		int t = i * i + j * j;
		if (sqrt(t) == (int)sqrt(t))return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (ok(n) ? "YES" : "NO") << endl;
	}
}
