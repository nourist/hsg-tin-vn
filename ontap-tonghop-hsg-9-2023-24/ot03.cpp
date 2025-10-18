#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[(int)1e5 + 8];

int main() {
	freopen("querythree.inp", "r", stdin);
	freopen("querythree.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> d[i];
	for (int i = 2; i <= n; i++)d[i] += d[i - 1];

	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= i) {
			if (d[i] - d[j - 1] <= k) {
				cout << j << endl;
				break;
			}
			else {
				if (j == i) {
					cout << -1 << endl;
				}
				j++;
			}
		}
	}
}
