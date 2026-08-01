#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b1"

const int mod = 123456789;

struct Matrix {
	vector<vector<int>>m;

	Matrix(int n) : m(vector<vector<int>>(n, vector<int>(n, 0))) {}
	Matrix(vector<vector<int>>_m) : m(_m) {}

	const int size() const {
		return m.size();
	}

	const auto& operator [] (int i) const {
		return m[i];
	}

	auto& operator [] (int i) {
		return m[i];
	}

	static Matrix base(int n) {
		Matrix res(n);
		FOR(i, 0, n - 1)res[i][i] = 1;
		return res;
	}
};

Matrix operator * (const Matrix& a, const Matrix& b) {
	int n = a.size();
	Matrix res(n);

	FOR(i, 0, n - 1)FOR(j, 0, n - 1) FOR(k, 0, n - 1) {
		res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j] % mod) % mod;
	}

	return res;
}

Matrix operator ^ (const Matrix& a, ll n) {
	if (n == 0)return Matrix::base(a.size());

	Matrix t = a ^ (n / 2);
	if (n % 2 == 0)return t * t;
	return t * t * a;
}

int f0[102];
int f1[102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, k, m;
	cin >> n >> k >> m;

	int blocks = k / m;
	int reman = k - blocks * m;

	FOR(i, 0, m - 1) {
		int cnt = blocks + (i != 0 && i <= reman);
		if (m % 2 == 0) {
			if (i % 2 == 0)f0[i] = cnt;
			else f1[i] = cnt;
		}
		else {
			if (cnt % 2 == 0) {
				f0[i] = cnt / 2;
				f1[i] = cnt / 2;
			}
			else {
				f0[i] = cnt / 2 + ((i == 0 ? m : i) % 2 == 0);
				f1[i] = cnt / 2 + ((i == 0 ? m : i) % 2 == 1);
			}
		}
	}


	Matrix Odd(m), Even(m);
	FOR(i, 0, m - 1)FOR(j, 0, m - 1) {
		Odd[i][j] = f1[(i - j + m) % m];
		Even[i][j] = f0[(i - j + m) % m];
	}

	Matrix res = (Odd ^ (n / 2)) * (Even ^ (n / 2));
	if (n % 2 == 1)res = res * Odd;
	cout << res[0][0];
}