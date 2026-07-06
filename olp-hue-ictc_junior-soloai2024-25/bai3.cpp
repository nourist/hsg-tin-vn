#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[(ll)1e6], f[(ll)1e6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll j = 1;
	while (j <= 1e6) {
		d[j] = j;
		j *= 2;
	}

	for (ll i = 1; i <= 1e6; i++) {
		if (d[i] == 0)d[i] = d[i - 1];
	}

	ll l, r;
	cin >> l >> r;

	for (ll i = l; i <= r; i++) {
		for (ll j = l; j <= r; j++) {
			for (ll k = l; k <= r; k++) {
				for (ll h = l; h <= r; h++) {
					ll val = (i ^ j) ^ (k ^ h);
					while (val != 0) {
						f[d[val]]++;
						val -= d[val];
					}
				}
			}
		}
	}

	for (ll i = 1; i <= 1e6; i++) {
		if (f[i] != 0) {
			cout << i << ':' << f[i] << endl;
		}
	}
}
