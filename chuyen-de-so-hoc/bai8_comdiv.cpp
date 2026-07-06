#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int f[(int)1e6 + 6], d[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai8_comdiv.inp", "r")) {
		freopen("bai8_comdiv.inp", "r", stdin);
		freopen("bai8_comdiv.out", "w", stdout);
	}

	int n, x;
	cin >> n;
	FOR(i, 1, n) {
		cin >> x;
		f[x]++;
	}

	FOR(i, 1, 1e6) {
		for(int j = i; j <= 1e6; j += i) {
			d[i] += f[j];
		}
	}

	FOD(i, 1e6, 1) {
		if(d[i] >= 2) {
			cout << i;
			return 0;
		}
	}
}
