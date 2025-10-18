#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 6], l[(int)1e6 + 6], r[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i-1]) {
			l[i] = l[i - 1] + 1;
		}
		else {
			l[i] = 1;
		}
	}

	for (int i = n; i >= 1; i--) {
		if (a[i] >a[i+1]) {
			r[i] = r[i + 1] + 1;
		}
		else {
			r[i] = 1;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if(r[i+1]!=0&&l[i]!=1&&a[i+1]<a[i])
		res = max(res, l[i] + r[i + 1]);
	}
	cout << res;
}