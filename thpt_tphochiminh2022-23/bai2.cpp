#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int mod = 1e3 + 7;
int n, q;
int bit1[(int)4e5 + 5], bit2[(int)4e5 + 5];

void updateBit(int bit[], int idx, int v) {
	for (idx; idx <= n; idx += (idx & (-idx)))bit[idx] += v;
}

int queryBit(int bit[], int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
	return res;
}

void updateRange(int l, int r, int v) {
	updateBit(bit1, l, (n - l + 1) * v);
	updateBit(bit1, r + 1, (n - r) * -v);
	updateBit(bit2, l, v);
	updateBit(bit2, r + 1, -v);
}

int prefixQuery(int idx) {
	return queryBit(bit1, idx) - queryBit(bit2, idx) * (n - idx);
}

int rangeQuery(int u, int v) {
	return prefixQuery(v) - prefixQuery(u - 1);
}

int fib[111];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 108; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}

	cin >> n >> q;
	ll t, l, r, v;
	while (q--) {
		cin >> t >> l >> r;
		if (t == 1) {
			cin >> v;
			updateRange(l, r, fib[(v-1)%108]);
		}
		else {
			cout << rangeQuery(l, r) << '\n';
		}
	}
}
