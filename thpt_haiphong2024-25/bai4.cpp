#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int mod = 1e9 + 7;
int m[1008][1008];
int n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;

	m[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i + 1 <= n)
				m[i + 1][j] = (m[i + 1][j] + m[i][j]) % mod;
			if (j + 1 <= n)
				m[i][j + 1] = (m[i][j + 1] + m[i][j]) % mod;
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;

		cout << m[n - x + 1][n - y + 1] << endl;
	}
}
