#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n;
int a[(int)2e5 + 5];

void transform() {
	map<int, int>mp;
	for (int i = 1; i <= n; i++) {
		mp[a[i]] = 1;
	}

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->second = cnt++;
	}

	for (int i = 1; i <= n; i++) {
		a[i] = mp[a[i]];
	}
}

int BIT[(int)2e5 + 5];

void update(int idx) {
	for (idx; idx <= 2e5; idx += (idx & (-idx)))BIT[idx]++;
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res += BIT[idx];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	cin >> n;

	for (int i = 1; i <= n; i++)cin >> a[i];
	transform();
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res += query(2e5) - query(a[i]);
		update(a[i]);
	}
	cout << res;
}
