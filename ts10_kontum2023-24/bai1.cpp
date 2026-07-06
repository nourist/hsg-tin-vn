#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool d[(int)1e5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (sqrt(x) == (int)sqrt(x)) {
			d[(int)sqrt(x)] = 1;
		}
	}
	for (int i = 0; i <= 5e4; i++) {
		if (!d[i]) {
			cout << i * i;
			return 0;
		}
	}
}
