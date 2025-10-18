#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[(int)1e6 + 10];

void pt(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			d[i]++;
			return;
		}
	}
	d[n]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		pt(i);
	}
	
	while (n--) {
		int x;
		cin >> x;
		cout << d[x] << '\n';
	}
}
