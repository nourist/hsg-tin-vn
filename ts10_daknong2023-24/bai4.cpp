#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n, m, v;
	cin >> n >> m >> v;
	while (m--) {
		int l, r;
		cin >> l >> r;
		d[l] ++;
		d[r+1] --;
	}
	for (int i = 1; i <= n; i++) {
		d[i] += d[i - 1];
	}

	sort(d + 1, d + n + 1, greater<ll>());
	cout << (d[1] + d[2] + d[3])*v;
}
