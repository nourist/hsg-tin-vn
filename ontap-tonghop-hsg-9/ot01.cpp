#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[(int)1e5 + 8];

int main() {
	freopen("queryone.inp", "r", stdin);
	freopen("queryone.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> d[i];
	for (int i = 2; i <= n; i++)d[i] += d[i - 1];
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << d[r] - d[l - 1] << endl;
	}
}
