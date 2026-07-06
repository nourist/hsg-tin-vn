#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, k;
	string str;
	cin >>n>>k>> str;
	map<int, int>mp;
	for (int i : str)mp[i]++;
	bool ok = 0;
	for (auto i : mp) {
		if (i.second >= k) {
			cout << (char)i.first;
			ok = 1;
		}
	}
	if (!ok)cout << 0;
}
