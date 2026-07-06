#include<bits/stdc++.h>
using namespace std;
int n, q, l, r;
long long A[1000006], D[1000006], k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("BARRAY.INP", "r", stdin);
	freopen("BARRAY.OUT", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) D[i] = A[i] - A[i - 1];
	cin >> q;
	for (int query = 1; query <= q; query++) {
		cin >> l >> r >> k;
		D[l] += k;
		D[r + 1] -= k;
	}
	for (int i = 1; i <= n; i++)D[i] += D[i - 1];
	for (int i = 1; i <= n; i++) {
		A[i] = D[i] + A[i - 1];
		cout << A[i] << ' ';
	}
	return 0;
}