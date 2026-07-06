#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e5 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("phuongtrinh1.inp", "r", stdin);
	freopen("phuongtrinh1.out", "w", stdout);

	ll n, l = 0, p, r = 0, res = 0, sum = 0;
	cin >> n >> p;
	for (ll i = 0; i < n; i++)cin >> a[i];
	while (r < n) {
		sum += a[r];
		if (sum > p) {
			while (sum > p) {
				sum -= a[l];
				l++;
			}
		}
		if (sum == p)res++;
		r++;
	}
	cout << res;
}
