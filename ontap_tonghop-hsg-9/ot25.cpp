#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

map<int, bool>mp;

void uocnt(int i, int j, int k) {
	ll res = 1;
	while (i--) {
		res *= 2;
		if (res > 1e9)return;
	}
	while (j--) {
		res *= 3;
		if (res > 1e9)return;
	}
	while (k--) {
		res *= 5;
		if (res > 1e9)return;
	}
	mp[res] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("UOCNTMAX5.inp", "r", stdin);
	freopen("UOCNTMAX5.out", "w", stdout);

	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 13; k++) {
				uocnt(i, j, k);
			}
		}
	}

	vector<int>v;
	for (auto it : mp)v.push_back(it.first);

	ll q, x;
	cin >> q;
	while (q--) {
		cin >> x;
		if (mp[x]) {
			cout << "YES " << upper_bound(v.begin(), v.end(), x) - v.begin() << endl;

		}
		else {
			cout << "NO\n";
		}
	}
}
