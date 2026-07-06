#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[60][60], res[60][60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	if (k < 0)k = 4 + k;
	k %= 4;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)cin >> a[i][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = i, y = j;
			if (k == 1) {
				x = j;
				y = n - i+1;
			}
			else if (k == 2) {
				x = n - i + 1;
				y = n - j + 1;
			}
			else if(k==3) {
				y = i;
				x = n - j + 1;
			}
			res[x][y] = a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)cout << res[i][j] << ' ';
		cout << endl;
	}
}

