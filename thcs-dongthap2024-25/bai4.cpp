#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int bit[(int)1e6 + 6];

void update(int idx) {
	for (idx; idx <= 1e6; idx += (idx & (-idx))) {
		bit[idx]++;
	}
}

int query(int idx) {
	int res = 0;
	for (idx; idx > 0; idx -= (idx & (-idx))) {
		res += bit[idx];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n, x;
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		res += query(1e6) - query(x);
		update(x);
	}
	cout << res;
}
