#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

pair<int, int>v[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
	int l = 0, r = 0, res = 1e9;
	map<int, int>mp;
	sort(v, v + n);
	while (r < n) {
		mp[v[r].second]++;
		while (mp[1] >= 1 && mp[2] >= 1 && mp[3] >= 1) {
			res = min(res, v[r].first - v[l].first);
			mp[v[l++].second]--;
		}
		r++;
	}
	cout << (res==1e0?-1:res);
}
