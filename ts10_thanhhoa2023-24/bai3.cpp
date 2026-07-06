#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e7 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n, s;
	cin >> n>>s;
	for (int i = 0; i < n; i++)cin >> a[i];

	ll l = 0, r = 0, sum =0, res =1e9;
	while (r<n) {
		while (sum >= s) {
			res = min(res, r - l);
			sum -= a[l++];
		}
		sum += a[r++];
	}
	cout << (res==1e9?-1:res);
}
