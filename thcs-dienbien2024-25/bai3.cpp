#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, t;
	cin >> n;
	map<int, ll>mp;
	ll mi = 1e9, ma = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		mi = min(mi, t);
		ma = max(ma, t);
		mp[t]++;
		cnt = max(cnt, mp[t]);
	}
	cout << mi << ' ' << ma << endl << cnt;
}
