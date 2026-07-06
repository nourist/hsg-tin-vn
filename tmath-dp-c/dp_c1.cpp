#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define matrix vector<vector<ll>>

ll indianM(ll a, ll b, ll mod) {
	if (b == 0)return 0;
	ll tmp = indianM(a, b / 2, mod);
	if (b % 2 == 0)return (tmp + tmp) % mod;
	return (tmp + tmp + a) % mod;
}

matrix matrixM(matrix a, matrix b, ll mod) {
	//		00 01
	//		10 11
	//00 01
	//10 11
	return { {
		(indianM(a[0][0], b[0][0],mod) + indianM(a[0][1], b[1][0], mod)) % mod,
		(indianM(a[0][0] , b[0][1],mod) + indianM(a[0][1] , b[1][1],mod)) % mod
	},{
		(indianM(a[0][0] , b[1][0],mod) + indianM(a[1][0] , b[1][1],mod)) % mod,
		(indianM(a[0][1] , b[1][0],mod) + indianM(a[1][1] , b[1][1],mod)) % mod
	} };
}

matrix matrixP(matrix a, ll n, ll mod) {
	if (n == 1)return a;
	matrix tmp = matrixP(a, n / 2, mod);
	if (n % 2 == 0)return matrixM(tmp, tmp, mod);
	return matrixM(a, matrixM(tmp, tmp, mod), mod);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dp_c1.inp", "r")) {
		freopen("dp_c1.inp", "r", stdin);
		freopen("dp_c1.out", "w", stdout);
	}

	matrix mt = { {1,1},{1,0} };

	ll n, base;
	cin >> n >> base;
	cout << matrixP(mt, n, base)[0][1];
}
