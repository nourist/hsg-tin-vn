#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e6 + 10];
bool p2[(int)3e6 + 10];
vector<int>v;

void sieve(ll L, ll  R) {
	for (ll i = L; i <= R; i++) {
		p[i - L] = 1;
	}
	for (ll i : v) {
		if (i * i > R)break;
		for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
			p[j - L] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int q, n;
	cin >> q;

	memset(p2, 1, 3e6);
	p2[0] = p2[1] = 0;
	for (int i = 2; i * i <= 3e6; i++) {
		if (p2[i])for (int j = i * i; j <= 3e6; j += i) {
			p2[j] = 0;
		}
	}

	for (int i = 2; i <= 3e6; i++)if (p2[i])v.push_back(i);

	while (q--) {
		cin >> n;
		if (n <= 2e6) {
			cout << *lower_bound(v.begin(), v.end(), n) << '\n';
			continue;
		}
		sieve(n, n + 1e3);
		for (int i = n; i <= n + 1e3; i++) {
			if (p[i - n] && i >= 2) {
				cout << i << '\n';
				break;
			}
		}
	}
}
