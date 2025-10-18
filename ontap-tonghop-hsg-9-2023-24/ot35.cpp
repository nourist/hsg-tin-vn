#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, a[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("CACHNHIET.inp", "r", stdin);
	freopen("CACHNHIET.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] + max(0LL, a[n - i - 1] - a[i]);
	}
	cout << sum;
}
