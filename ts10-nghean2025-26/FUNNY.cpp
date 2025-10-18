#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll d[(int)120];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("FUNNY.inp", "r")) {
		freopen("FUNNY.inp", "r", stdin);
		freopen("FUNNY.out", "w", stdout);
	}

	ll a, b,t,k;
	cin >> t >> k;

	FOR(i, 0, 99) {
		d[i] = (i % k == 0);
		if (i != 0)d[i] += d[i - 1];
		}

	while (t--) {
		cin >> a >> b;
		cout << d[99] * (b / 100) + d[b % 100] - d[99] * ((a - 1) / 100) - d[(a - 1) % 100] << '\n';
	}
}
