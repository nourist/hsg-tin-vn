#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}
	
	unordered_map<int, int>mp;
		
	int n, m, s, res =0;
	cin >> n >> m >> s;
	for (int t, i = 0; i < n; i++) {
		cin >> t;
		mp[t]++;
	}
	for (int t, i = 0; i < m; i++) {
		cin >> t;
		res += mp[s - t];
	}
	cout << res;
}
