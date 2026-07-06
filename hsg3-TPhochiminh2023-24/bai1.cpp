#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5];
int pos[(int)1e5 + 5];
int bit[(int)1e5 + 5];

void update(int idx, int v) {
	for (idx; idx <= 1e5; idx += (idx & (-idx)))bit[idx] += v;
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
	return res;
}

int queryRange(int l, int r) {
	return query(r) - query(l - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i], pos[a[i]] = i, update(i,1);

	int l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			cout << queryRange(l, pos[l] - 1);
			update(pos[l], -1);
			l++;
		}
		else {
			cout << queryRange(pos[r] + 1, r);
			update(pos[r], -1);
			r--;
		}
		cout << '\n';
	}
}
