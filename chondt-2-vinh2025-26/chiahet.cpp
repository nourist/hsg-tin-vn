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

	if (fopen("chiahet.inp", "r")) {
		freopen("chiahet.inp", "r", stdin);
		freopen("chiahet.out", "w", stdout);
	}

	ll n, a, b;
	cin >> n >> a >> b;

	ll c = a / __gcd(a, b) * b;
	cout << n / a + n / b - n / c * 2;
}
