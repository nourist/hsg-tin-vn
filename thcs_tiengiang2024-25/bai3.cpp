#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, x;
	cin >> n;

	map<int, int>mp;

	for (int i = 1; i <= n; i++) {
		cin >> x;
		mp[x]++;
	}

	int res = 0;
	for (auto it : mp) {
		if (it.second >= 2) {
			cout << it.first << ' ' << it.second << endl;
		}
		else {
			res ++;
		}
	}
	cout << res;
}
