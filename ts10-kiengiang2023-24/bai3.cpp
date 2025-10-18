#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i < 1e5; i++) {
		if (p[i])for (int j = i * i; j < 1e5; j += i) {
			p[j] = 0;
		}
	}

	ll n;
	cin >> n;
	int res = 0;
	for (int i = 2; i * i <= n; i++) {
		res += p[i];
	}
	cout << res;
}
