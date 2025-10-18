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

	int a[200], n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int res = abs(a[1] - a[0]);
	for (int i = 2; i < n; i++)res = __gcd(res, abs(a[i] - a[i - 1]));
	vector<int>v;
	v.push_back(res);
	for (int i = 2; i * i <= res; i++) {
		if (res % i == 0) {
			cout << i << ' ';
			if (i * i != res)v.push_back(res / i);
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)cout << v[i] << ' ';
}
