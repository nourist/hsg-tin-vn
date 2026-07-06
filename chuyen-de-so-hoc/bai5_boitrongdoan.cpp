#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

#define lcm(a, b) ((a) / __gcd(a, b) * (b))

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5_boitrongdoan.inp", "r")) {
		freopen("bai5_boitrongdoan.inp", "r", stdin);
		freopen("bai5_boitrongdoan.out", "w", stdout);
	}

	int n, l, r,x,c=1;
	cin >> n >> l >> r;
	while (n--) {
		cin >> x;
		c=lcm(c, x);
	}
	cout << r / c - (l - 1) / c << endl;
}
