#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, k;
ll a[(int)1e6 + 6];

ll mini(ll x) {
	if (x > 0)return x % k;
	return (k - (-x % k))%k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("chiak.inp", "r")) {
		freopen("chiak.inp", "r", stdin);
		freopen("chiak.out", "w", stdout);
	}

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	for(int i = 1; i <= n; i++) {
		a[i] = mini(a[i]);
	}
	ll res = 0;
	unordered_map<int, int>mp;
	mp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0)res += mp[0];
		else res+=mp[a[i]];
		mp[a[i]]++;
	}
	cout << res;
}
