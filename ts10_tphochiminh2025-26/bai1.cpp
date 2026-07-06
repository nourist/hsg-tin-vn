#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll floor(ll n) {
	ll l = 0, r = 1e10;
	ll res=0;
	while (l <= r) {
		ll mid = l + r >> 1;
		if (mid * (mid + 1)/2 <n) {
			res = max(res, mid);
			l = mid + 1;
		}
		else r = mid-1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n;
	cin >> n;

	ll x = floor(n);
	cout << x+1<<' '<<n-x*(x+1)/2;
}
