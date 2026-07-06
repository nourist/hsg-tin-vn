#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int f[(int)1e7 + 7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("YesDivisor.inp", "r")) {
		freopen("YesDivisor.inp", "r", stdin);
		freopen("YesDivisor.out", "w", stdout);
	}

	for (int i = 1; i * i <= 1e7; i++) {
		for (int j = i * i; j <= 1e7; j += i) {
			f[j]++;
			if (i * i != j) {
				f[j]++;
			}
		}
	}

	int n, k;
	cin >> n >> k;

	int res = 0;
	FOR(i, 1, n) {
		if (f[i] <= k)res++;
	}
	cout << res;
}
