#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e6 + 10];

bool ok(ll n) {
	if (!p[n])return 0;
	ll s = 0;
	while (n != 0) {
		s += n % 10;
		n /= 10;
	}
	return p[s];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 1e6; j += i) {
				p[j] = 0;
			}
		}
	}
	ll n, x, res =0;
	cin >> n;
	while (n--) {
		cin >> x;
		if (ok(x))res++;
	}
	cout << res;
}
