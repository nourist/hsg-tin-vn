#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e4];
int l[(int)1e4];
int r[(int)1e4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("vitamin.inp", "r")) {
		freopen("vitamin.inp", "r", stdin);
		freopen("vitamin.out", "w", stdout);
	}

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		l[i] = l[i - 1] + a[i];
	}
	for (int i = n - 1; i >= 1; i--) {
		r[i] = r[i + 1] + a[i];
	}
	map<int, int>m;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			m[l[i] + r[j]]=i;
		}
	}
	for (int i = 1; i * a[n] <= x; i++) {
		if(m[x - i * a[n]]!=0) {
			cout << i*n+m[x - i * a[n]];
			return 0;
		}
	}
	cout << -1;
}
