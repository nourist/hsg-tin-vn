#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

pair<int, int>a[(int)5e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n;
	cin >> n;

	for (ll i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n, [&](pair<int, int> x, pair<int, int> y) {
		if (x.second-x.first==y.second-y.first) {
			return x.second > y.second;
		}
		else {
			return x.second - x.first > y.second - y.first;
		}
		});
	// for (int i = 0; i < n; i++) {
		// cerr << a[i].first << ' ' << a[i].second << endl;
	// }

	ll sum = 0;
	for (int i = 0; i < n / 2; i++) {
		sum += a[i].second;
	}
	for (int i = n / 2; i < n; i++) {
		sum += a[i].first;
	}
	cout << sum;
}
