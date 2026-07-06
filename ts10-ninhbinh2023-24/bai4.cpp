#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n, x, res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		res = max(res, x);
	}
	cout << res;
}

/*
9
1 3 6 1 5 6 4 7 11

1 4 10 11 16 22 26 33 44
2: 11
5: 1
11: 4
13: 1

*/