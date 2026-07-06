#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

vector<pair<ll,ll>>a[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;

	for (ll x,y,c, i = 1; i <= n+m; i++) {
		cin >> x >> y >> c;
		a[c].push_back({ x,y });
	}

	sort(a[0].begin(), a[0].end(), [&](pair<ll, ll>x, pair<ll, ll>y) {
		return x.first - x.second < y.first - y.second;
		});

	ll sum1 = 0, sum2 = 0;
	for (pair<ll,ll> i : a[1]) {
		sum1 += i.first;
	}
	for (pair<ll, ll>i : a[2]) {
		sum2 += i.second;
	}

	ll need1 = n - a[1].size();
	for (int i = 0; i < need1; i++)sum1 += a[0][i].first;
	for (int i = need1; i < a[0].size(); i++)sum2 += a[0][i].second;
	cout << sum1 + sum2;
}
