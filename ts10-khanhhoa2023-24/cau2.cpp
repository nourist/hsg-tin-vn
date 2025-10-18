#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	int n, a, b, x, res = 0;
	cin >> n>>a >> b;
	if (a > b)swap(a, b);
	res = n * a;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 2)res += b;
	}
	cout << res;
}
