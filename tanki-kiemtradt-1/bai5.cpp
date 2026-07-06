#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (long long i = l; i <= r; ++i)
#define FOD(i,r,l) for (long long i = r; i >= l; --i)
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define ll long long
#define ld long double
#define lcm(a, b) (a/__gcd(a,b)*b)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;
	ll res = n;

	FOR(mask, 1, (1 << k-1) - 1) {
		ll sum = 1, cnt = 0;
		FOR(i, 0, k - 1) {
			if (BIT(mask, i)) {
				sum = lcm(sum, (i + 2));
				cnt++;
			}
		}
		if (cnt % 2) {
			res -= n/sum;
			// cout << "-" << n / sum << endl;
		}
		else {
			res += n / sum;
			// cout << "+" << n / sum << endl;
		}
	}
	cout << res;
}
