#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	ll n;
	cin >> n;
	vector<string>v;
	ll i = 2;
	while (i * i <= n) {
		while (n % i == 0) {
			v.push_back(to_string(i));
			n /= i;
		}
		i++;
	}
	if (n != 1)v.push_back(to_string(n));
	sort(v.begin(), v.end(), [&](string a, string b) {
		return a + b > b + a;
		});
	for (string i : v)cout << i;
}
