#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool p[(int)1e7 + 7];
int f[(int)1e7 + 7];
bool rem[(int)1e7 + 7];

const ll mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("THANDEN.inp", "r")) {
		freopen("THANDEN.inp", "r", stdin);
		freopen("THANDEN.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e7; i++)
		if (p[i])
			for (int j = i * i; j <= 1e7; j += i)
				p[j] = 0;

	int n;
	cin >> n;

	FOR(i, 1, n) {
		if (!p[i])continue;

		int cur = i;
		while (cur <= n) {
			f[i] += n / cur;
			cur *= i;
		}
	}

	FOR(i, 1, n) {
		if (f[i] % 2 == 1) {
			rem[i] = 1;
		}
	}

	ll res = 1;
	FOR(i, 1, n) {
		if (rem[i])continue;

		res = res * i % mod;
	}

	cout << res;
}
