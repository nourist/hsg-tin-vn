#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("ENERGY.inp", "r")) {
		freopen("ENERGY.inp", "r", stdin);
		freopen("ENERGY.out", "w", stdout);
	}

	ll n;
	cin >> n;
	cout << __builtin_popcountll(n);
}
