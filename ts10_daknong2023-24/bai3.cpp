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

	ll n;
	cin >> n;
	ll a = n * (n + 1) / 2;
	ll b = (2 * n + 1);
	if (a % 3 == 0)cout << a / 3 % 100 * b % 100;
	else cout << b / 3 % 100 * a % 100;
}
