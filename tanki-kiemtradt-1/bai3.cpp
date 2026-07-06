#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
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

	ll s, k;
	cin >> k >> s;
	ll n = s - k;
	cout << n << endl;
	cout << "5000 " << n / 5000 << endl;
	n %= 5000;
	cout << "2000 " << n / 2000 << endl;
	n %= 2000;
	cout << "1000 " << n << endl;
}
