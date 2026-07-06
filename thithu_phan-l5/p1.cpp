#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool ok(int n) {
	FOR(i, 0, 10) {
		if (n - i * 111 >= 0 && (n - i * 111) % 11 == 0)return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("p1.inp", "r")) {
		freopen("p1.inp", "r", stdin);
		freopen("p1.out", "w", stdout);
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (ok(n))cout << "YES\n";
		else cout << "NO\n";
	}
}

/*
n = 111 * (11 * a + b) + 11 * y
n = 111 * 11 * a + 11 * y + 111 * b
*/