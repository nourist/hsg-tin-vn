#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)2e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, k;
	cin >> n>>k;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	int res = 0;
	for (int i = 1; i < n; i++) {
		res += upper_bound(a, a + i, k-a[i]) - lower_bound(a, a + i, k-a[i]);
	}
	cout << res;
}
