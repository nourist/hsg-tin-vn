#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll mod = 1e9 + 7;

struct matrix {
	vector<vector<ll>>data;

	matrix() = default;
	matrix(ll r, ll c) : data(r, vector <ll>(c)) {}

	auto& operator [] (ll i) { return data[i]; }
	const auto& operator[] (ll i) const { return data[i]; }

	ll row() const {
		return data.size();
	}

	ll col() const {
		return data[0].size();
	}

	matrix operator * (const matrix &b) {
		matrix a = *this;

		matrix c(a.row(), b.col());
		for (ll i = 0; i < a.row(); ++i)
			for (ll j = 0; j < b.col(); ++j)
				for (ll k = 0; k < a.col(); ++k)
					c[i][j] = (c[i][j]+a[i][k] * b[k][j])%mod;
		return c;
	}
};

matrix bpow(matrix a, ll n) {
	if (n == 1)return a;
	matrix t = bpow(a, n / 2);
	if (n % 2 == 0)return t * t;
	return t * t * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dp_c10.inp", "r")) {
		freopen("dp_c10.inp", "r", stdin);
		freopen("dp_c10.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;

	matrix a(1, k);
	ll sum = 2;
	a[0][0] = a[0][1] = 1;
	for (ll i = 2; i < k; i++) {
		a[0][i] = sum;
		sum += a[0][i];
	}

	matrix b(k, k);
	for (ll i = 1; i < k; i++)b[i][i - 1] = 1;
	for (ll i = 0; i < k; i++)b[i][k - 1] = 1;

	cout << ((a*bpow(b, n - k + 1))[0][k-1]);
}