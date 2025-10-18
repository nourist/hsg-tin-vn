#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[1000005], b[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++) {
		if (a[i] == b[0]) {
			cout <<  b[1]-a[i];
		}
		else {
			cout << b[0]-a[i];
		}
		cout << ' ';
	}
}
