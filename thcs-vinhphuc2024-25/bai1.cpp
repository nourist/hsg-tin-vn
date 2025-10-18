#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;
	if (n == m && n % 2 == 0)
		cout << n * 4 - 5;
	else if (n == m)
		cout << n * 4 - 4;
	else if (n < m)
		cout << n * 3 + m - 4;
	else
		cout<<m * 3 + n - 4;
}
