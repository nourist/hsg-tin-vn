#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name ""

bool p[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e6; i++)if (p[i])for (int j = i * i; j <= 1e6; j += i)p[j] = 0;

	ll a, b;
	cin >> a >> b;
	int res = 0;
	for (ll i = ceil(sqrt(a)); i <= sqrt(b); i++) {
		res += p[i];
	}
	cout << res;
}
