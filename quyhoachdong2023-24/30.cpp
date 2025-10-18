#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 10], d[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("DPFIBO2.inp", "r", stdin);
	freopen("DPFIBO2.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	for (int x, i = 0; i < k; i++)cin >> x, d[x] = 1;
	if (!d[1])a[1] = 1;
	if (!d[2])a[2] = 1;
	for (int i = 3; i <= n; i++)a[i] = (d[i] ? 0 : (a[i - 1] + a[i - 2]) % (14062008));
	cout << a[n];
}
