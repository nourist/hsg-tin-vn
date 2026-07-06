#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e3 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n, greater<int>());

	ll res = 0;
	for (int i = 0; i < n; i++) {
		if ((i + 1) % k != 0||i>=n/k*k) {
			res += a[i];
		}
	}
	cout << res;
}
