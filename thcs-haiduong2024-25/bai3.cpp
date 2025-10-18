#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)3e5 + 100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	ll res = 0, cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1])cnt++;
		else {
			res += cnt / 4;
			cnt = 1;
		}
	}
	res += cnt / 4;
	cout << res;
}
