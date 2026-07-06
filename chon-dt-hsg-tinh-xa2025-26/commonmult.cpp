#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

#define lcm(a,b) (a/__gcd(a,b)*b)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("commonmult.inp", "r")) {
		freopen("commonmult.inp", "r", stdin);
		freopen("commonmult.out", "w", stdout);
	}

	ll a, b, c, n;
	cin >> n >> a >> b >> c;

	ll x = lcm(a, lcm(b, c));
	for (int i = x; i <= n; i += x) {
		cout << i << ' ';
	}
}
