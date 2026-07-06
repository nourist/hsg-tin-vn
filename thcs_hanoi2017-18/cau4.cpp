#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	int n, m, k;
	cin >> n >> m >> k;

	map<int, int> mp;
	for (int i = 0; i < n * m; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	vector<pair<int,int>> a;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		a.push_back({it->second, it->first});
	}
	sort(a.begin(), a.end(), greater<pair<int,int>>());
	int res = 0;
	for(int i = 0; i < a.size(); i++) {
		k--;
		res += a[i].first;
		if(k == 0) {
			break;
		}
	}

	cout << res;
}
