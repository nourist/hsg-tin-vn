#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e6 + 10], d[(ll)1e6 + 10];
int p[(ll)1e6 + 10];

ll transformN(ll n) {
	unordered_map<ll, ll>mp;
	while (n != 1) {
		mp[p[n]]++;
		n /= p[n];
	}
	ll res = 1;
	for (auto i : mp)if (i.second % 2)res *= i.first;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	for (int i = 1; i <= 1e6; i++)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i] == i) {
			for (int j = i * i; j <= 1e6; j += i) {
				if (p[j] == j)p[j] = i;
			}
		}
	}

	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)cin >> a[i], d[transformN(a[i])]++;
	ll res = 0;
	for (int i = 0; i <= 1e6; i++)res += d[i] * (d[i] - 1) / 2;
	cout << res;
}
