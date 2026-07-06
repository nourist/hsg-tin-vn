#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;
	for (int i = 0, t; i < n; i++)cin >> t, d[t]++;
	int s = 0, t = 0;
	for (int i = 0; i <= k; i++) {
		s += d[i];
		t = max(t, d[i]);
	}
	cout << s << endl << t;
}
