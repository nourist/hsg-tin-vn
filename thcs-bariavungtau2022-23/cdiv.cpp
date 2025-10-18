#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cdiv.inp", "r")) {
		freopen("cdiv.inp", "r", stdin);
		freopen("cdiv.out", "w", stdout);
	}

	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = 1; j * j <= x; j++) {
			if (x % j == 0) {
				d[j]++;
				if (j * j != x)d[x / j]++;
			}
		}
	}
	for (int i = 1e6; i >= 1; i--) {
		if (d[i] > 1) {
			cout << i;
			return 0;
		}
	}
}
