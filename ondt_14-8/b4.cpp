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
#define Name "b4"

const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	string a, b;
	cin >> n >> a >> b;
	a = "_" + a;
	b = "_" + b;

	FOR(i, 1, n) {
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
	}

	ll sum1 = 0;
	ll sum2 = 0;
	FOR(i, 1, n) {
		sum1 = (sum1 * 10 + a[i] - '0') % mod;
		sum2 = (sum2 * 10 + b[i] - '0') % mod;
	}

	cout << sum1 * sum2 % mod;

}

/*
(a * 10 + c) * (b * 10 + d) = a*b*100 + c*b*10 + d*a*10 + c*d
*/
