#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[444];

void pt(ll n, ll pl = 1) {
	ll i = 2;
	while (n != 1) {
		while (n % i == 0) {
			d[i]+=pl;
			n /= i;
		}
		i++;
	}
	if (n != 1)d[n]+=pl;
}

ll solve(ll n, ll k) {
	fill(d, d + 444, 0);

	for (int i = 1; i <= n; i++) {
		pt(i);
	}

	for (int i = 1; i <= k; i++)pt(i, -1);
	for (int i = 1; i <= n - k; i++)pt(i, -1);

	ll res = 1;
	for (int i = 1; i <= 432; i++) {
		res *= (d[i] + 1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("divisors.inp", "r")) {
		freopen("divisors.inp", "r", stdin);
		freopen("divisors.out", "w", stdout);
	}

	ll n, k;
	while (cin >> n >> k) {
		cout << solve(n, k)<<'\n';
	}
}
