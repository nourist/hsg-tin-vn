#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int pow3(int n) {
	if (n == 0) return 1;
	if (n == 1) return 3;
	if (n % 2 == 0) {
		int t = pow3(n / 2);
		return t * t %  4;
	} else {
		return 3 * pow3(n - 1) % 4;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n;
	cin >> n;

	int x = pow3(n);

	switch (x)
	{
	case 0:
		cout << 1 << endl;
		break;
	case 1:
		cout << 2 << endl;
		break;
	case 2:
		cout << 4 << endl;
		break;
	case 3:
		cout << 3 << endl;
	default:
		break;
	}
}
