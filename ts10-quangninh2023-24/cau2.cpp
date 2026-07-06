#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	int a[10];
	cin >> a[1] >> a[2] >> a[3];
	sort(a + 1, a + 4);
	if (a[2] - a[1] == a[3] - a[2]) {
		if (a[1] - (a[2] - a[1]) >= 1) {
			cout << a[1] - (a[2] - a[1]) << ' ';
		}
		cout << a[3] + (a[2] - a[1]);
	}
	else if (a[2] - a[1] > a[3] - a[2]) {
		cout << a[1] + (a[3] - a[2]);
	}
	else {
		cout << a[2] + (a[2] - a[1]);
	}
}
