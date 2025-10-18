#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name "ZFACTOR"

int f[(int)1e6 + 8];
int d[(int)1e6 + 8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	int n, k;
	cin >> n >> k;

	for (int i = 2; i * i <= k; i++) {
		if (f[i] == 0) {
			for (int j = i * i; j <= k; j += i) {
				if (f[j] == 0) {
					f[j] = i;
				}
			}
		}
	}

	for (int i = 2; i <= k; i++) {
		if (f[i] == 0) {
			f[i] = i;
		}
	}

	for (int i = 2; i <= k; i++) {
		d[f[i]]++;
	}

	while (n--) {
		int t;
		cin >> t;
		cout << d[t] << '\n';
	}
}
