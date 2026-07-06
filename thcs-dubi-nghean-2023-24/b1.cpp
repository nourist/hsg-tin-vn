#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("b1.inp", "r")) {
		freopen("b1.inp", "r", stdin);
		freopen("b1.out", "w", stdout);
	}

	ll n;
	cin >> n;

	ll l = n / 2, r;
	if (n % 2 == 0)r = n / 2;
	else r = n / 2 + 1;
	while (l >= 1) {
		if (__gcd(l, r) == 1) {
			cout << l << ' ' << r;
			return 0;
		}
		l--;
		r++;
	}
}
