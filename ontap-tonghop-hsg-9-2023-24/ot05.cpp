#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int limit = 1e6 + 8;
int a[limit];
ll d[limit];

int main() {
	freopen("dankien2.inp", "r", stdin);
	freopen("dankien2.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	d[0] = a[0];
	for (int i = 1; i < n; ++i) {
		d[i] = d[i - 1] + a[i];
	}

	for (int i = 0; i < n; ++i) {
		ll left_sum = (i == 0) ? 0 : d[i - 1];
		ll right_sum = d[n - 1] - d[i];
		cout << (a[i] * i - left_sum) + (right_sum - a[i] * (n - i - 1)) << '\n';
	}
}
