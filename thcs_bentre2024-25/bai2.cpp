#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n;
	int res = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			res=max(res, __gcd(a[i], a[j]));
		}
	}
	cout << res;
}
