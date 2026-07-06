#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 6];
ll d[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("seq11.inp", "r")) {
		freopen("seq11.inp", "r", stdin);
		freopen("seq11.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll sum = 0, cnt = 0, res =0;
	a[0] = -1e7;
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			sum += a[i];
			cnt++;
		}
		else {
			d[cnt] = max(d[cnt], sum);
			res = max(res, cnt);
			sum = a[i];
			cnt = 1;
		}
	}
	d[cnt] = max(d[cnt], sum);
	res = max(res, cnt);

	cout << d[res];
}
