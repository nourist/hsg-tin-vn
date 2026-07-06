#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name "DOCAO"

bool p[(int)1e6 + 19];

ll sum(int n) {
	ll res = 0;
	while (n != 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(name".inp", "r")) {
		freopen(name".INP", "r", stdin);
		freopen(name".OUT", "w", stdout);
	}

	int n, h;
	cin >> n >> h;
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		if (p[i])for (int j = i * i; j <= n; j += i) {
			p[j] = 0;
		}
	}

	int res = 0;
	for (ll i = 2; i <= n; i++) {
		if (p[i] && sum(i) == h) {
			cout << i << '\n';
			res++;
		}
	}
	cout << res;
}
