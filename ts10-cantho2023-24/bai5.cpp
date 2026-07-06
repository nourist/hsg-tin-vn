#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	ll m, n, x, y;
	cin >> m >> n >> x >> y;

	if (x % 2)
		cout << (x - 1) * n + y;
	else
		cout << (x-1)*n+(n-y+1);
}
