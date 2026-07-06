#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("vongso.inp", "r")) {
		freopen("vongso.inp", "r", stdin);
		freopen("vongso.out", "w", stdout);
	}

	int n, k;
	cin >> n>>k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	for (int i = 1; i <= n*2; i++)a[i] += a[i - 1];
	int res = -1e9;
	for (int i = k; i <= n * 2; i++) {
		res = max(res, a[i] - a[i - k]);
	}
	cout << res;
}
