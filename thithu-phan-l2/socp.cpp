#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool used[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("socp.inp", "r")) {
		freopen("socp.inp", "r", stdin);
		freopen("socp.out", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n) {
		int x;
		cin >> x;
		if (sqrt(x) == (int)sqrt(x)) {
			used[(int)sqrt(x)] = 1;
		}
	}

	FOR(i, 0, 1e6) {
		if (!used[i]) {
			cout << i * i;
			return 0;
		}
	}
}
