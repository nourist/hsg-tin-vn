#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;

	ll c1 = n / k, c2 = 2 * n / k;

	ll res = 0;
	// if ((n + 1) % k == 0)res += n;//mid

	//left
	res += c1 * (c1 + 1) / 2 * k - c1;

	//right
	res += (2 * n + 1) * (c2 - c1) - (c2 * (c2 + 1) / 2 - c1 * (c1 + 1) / 2) * k;

	cout << res;
}
