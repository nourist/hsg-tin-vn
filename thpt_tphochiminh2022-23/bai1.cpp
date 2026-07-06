#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[1003][1003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int n;
	cin>>n;

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> a[i][j];

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			sum += a[i][j];
		}
		if (a[i][i] < sum) {
			cout << "NO";
			return 0;
		}
		if (a[i][i] != sum)cnt++;
	}
	if (cnt != 0)cout << "YES" << endl << cnt;
	else cout << "NO";
}
