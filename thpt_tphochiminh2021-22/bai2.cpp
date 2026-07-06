#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, p, a, b, r;
	cin >> n >> p >> a >> b >> r;

	n %= p;
	if (n > r) {
		cout << -1;
		return 0;
	}

	r -= n;

	
}
