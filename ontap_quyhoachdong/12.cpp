#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'

const int limit = 1e6 + 8;
int a[limit], f[limit], b[limit];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	f[0] = a[0];
	for (int i = 1; i < n; i++)f[i] = max(f[i - 1], a[i]);
	b[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)b[i] = min(b[i + 1], a[i]);
	int res = 0;
	for (int i = 1; i < n - 1; i++) {
		res = max(res, f[i - 1] + a[i] - b[i + 1]);
	}
	cout << res;
}
