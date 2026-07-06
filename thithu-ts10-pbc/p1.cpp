#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll sum(ll x) {
	ll sum = 0;
	for (ll i = 1; 1; i++) {
		if (sum + i > x) {
			return i - 1;
		}
		sum += i;
	}
}

ll solve(ll n) {
	ll i = 2, res = 0;
	while (i*i<=n) {
		if (n % i == 0) {
			ll cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			res += sum(cnt);
		}
		i++;
	}
	if (n != 1) {
		res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("p1.inp", "r")) {
		freopen("p1.inp", "r", stdin);
		freopen("p1.out", "w", stdout);
	}

	ll n;
	cin >> n;
	cout << solve(n);
}
