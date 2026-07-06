#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

bool prime(ll n) {
	for (ll i = 2; i * i <= n; i++)if (n % i == 0)return 0;
	return n > 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("minnt.inp", "r")) {
		freopen("minnt.inp", "r", stdin);
		freopen("minnt.out", "w", stdout);
	}

	ll n;
	cin >> n;

	for (ll i = sqrt(n); 1; i++) {
		if (prime(i) && i * i >= n) {
			cout << i * i;
			return 0;
		}
	}
}