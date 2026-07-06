#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)2e6+6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("khlt.inp", "r")) {
		freopen("khlt.inp", "r", stdin);
		freopen("khlt.out", "w", stdout);
	}

	ll n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)cin >> a[i];

	ll l = 0, r = 0;
	ll sum = 0, res = 1e9;

	while (r < n) {
		sum += a[r];
		while (sum >= s) {
			res = min(res, r - l + 1);
			sum -= a[l++];
		}
		r++;
	}
	cout << (res == 1e9 ? -1 : res) << "\n";
}
