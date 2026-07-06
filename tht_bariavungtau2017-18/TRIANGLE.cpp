#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("TRIANGLE.inp", "r")) {
		freopen("TRIANGLE.inp", "r", stdin);
		freopen("TRIANGLE.out", "w", stdout);
	}

	ll n;
	cin >> n;
	n %= 2018;
	cout << n * n * n % 2018;
}
