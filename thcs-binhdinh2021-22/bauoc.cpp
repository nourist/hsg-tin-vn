#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bauoc.inp", "r")) {
		freopen("bauoc.inp", "r", stdin);
		freopen("bauoc.out", "w", stdout);
	}

	memset(p, true, sizeof(p));
	p[0] = p[1] = false;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 1e6; j += i) {
				p[j] = false;
			}
		}
	}

	ll n;
	cin >> n;
	ll res = 0;
	for (ll i = 1; i * i <= n; i++)res += p[i];
	cout << res;
}