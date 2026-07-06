#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll luythua(ll x, ll n) {
	if (n == 0)return 1;
	return x * luythua(x, n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, x, res = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		res += luythua(x / 10, x % 10);
	}
	cout << res;
}
