#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 2; i <= n + 1; i++)cin >> a[i];
	int res = 0;
	for (int i = 2; i <= n + 1; i++) {
		if (a[i - 1] >= a[i] || a[i + 1] >= a[i] || a[i - 2] >= a[i] || a[i + 2] >= a[i])
			res = max(res, a[i]);
	}
	cout << res;
}