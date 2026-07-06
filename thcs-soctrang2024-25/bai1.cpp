#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll bPow(ll x, ll n, ll m) {
	if (n == 0)return 1;
	ll t = bPow(x, n / 2, m);
	if (n % 2 == 0) return t * t % m;
	return x * t % m * t % m;
}

bool test(ll a, ll n, ll k, ll m) {
	ll mod = bPow(a, m, n);
	if (mod == 1 || mod == n - 1) return true;
	for (ll i = 1; i < k; i++) {
		mod = (mod * mod) % n;
		if (mod == n - 1) return true;
	}
	return false;
}

bool millerRabin(ll n) {
	if (n == 2 || n == 3 || n == 5 || n == 7) return true;
	if (n < 11)return false;
	ll k = 0, m = n - 1;
	while (m % 2 == 0) {
		k++;
		m /= 2;
	}
	vector<ll>p = { 2, 3, 5, 7 };
	for (ll a : p) {
		if (!test(a,n,k,m)) {
			return false;
		}
	}
	return true;
}

ll a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)cin >> a[i];
	vector<ll>res;
	for (int i = 0; i < n; i++) {
		if (millerRabin(a[i])) {
			res.push_back(a[i]);
		}
	}
	sort(res.begin(), res.end());
	if (k <= res.size())
		cout << res[k - 1];
	else cout << -1;
}
