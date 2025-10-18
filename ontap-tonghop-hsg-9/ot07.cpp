#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e5 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("phuongtrinh2.inp", "r", stdin);
	freopen("phuongtrinh2.out", "w", stdout);

	ll n, p, q, r;
	ll x = 0, y = 0, z = 0, w = 0, res = 0, s1 = 0, s2 = 0, s3 = 0;
	cin >> n >> p >> q >> r;
	for (ll i = 0; i < n; i++)cin >> a[i];
	while (w < n) {
		s3 += a[w];
		while (s3 > r) {
			s3 -= a[z];
			s2 += a[z++];
		}
		while (s2 > q) {
			s2 -= a[y];
			s1 += a[y++];
		}
		while (s1 > p) {
			s1 -= a[x++];
		}
		if (s1 == p && s2 == q && s3 == r)res++;
		w++;
	}
	cout << res;
}
