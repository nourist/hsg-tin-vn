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

	ll n, x;
	cin >> n;
	vector<ll>res;
	while (n--) {
		cin >> x;
		if (abs(x - 5) % 3 == 0) {
			res.push_back(x);
		}
	}
	if (res.empty())cout << 0;
	else 
	for (ll i : res)cout << i << ' ';
}
