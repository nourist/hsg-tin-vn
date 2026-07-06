#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll a[(int)1e5 + 5];
ll res[(int)1e5 + 5];
ll fact[30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	fact[0] = 1;
	FOR(i, 1, 20)fact[i] = fact[i - 1] * i;

	ll n, k;

	cin >> n >> k;
	FOR(i, 1, n) {
		ll x;
		cin >> x;
		a.push_back(x);
	}


}
