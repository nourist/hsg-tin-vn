#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("DPFIBO.inp", "r", stdin);
	freopen("DPFIBO.out", "w", stdout);

	int n;
	cin >> n;
	a[1] = a[2] = 1;
	for (int i = 3; i <= n; i++)a[i] = (a[i - 1] + a[i - 2]) % ((int)1e9 + 7);
	cout << a[n];
}
