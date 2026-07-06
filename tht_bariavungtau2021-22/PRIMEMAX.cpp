#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)3e4 + 5];

bool isp(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("primemax.inp", "r")) {
		freopen("primemax.inp", "r", stdin);
		freopen("primemax.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 3e4; ++i) {
		if (p[i]) {
			for (int j = i * i; j <= 3e4; j += i) {
				p[j] = 0;
			}
		}
	}

	int n;
	cin >> n;

	pair<int, int>res;
	for (int i = 2; i * i <= n; i++) {
		if(p[i]) for (int j = n / i; j > i; j--) {
			if (isp(j)) {
				if(i*j>res.first*res.second) res = {i,j};
				break;
			}
		}
	}
	cout << res.first << " " << res.second;
}
