#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n, greater<int>());
	ll sum = accumulate(a, a + n, 0);
	for (int i = 0; i < n/2; i++) {
		sum += a[i] - a[n - i - 1];
	}
	cout << sum;
}
