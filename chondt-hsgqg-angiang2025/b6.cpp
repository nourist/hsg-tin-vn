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
#define Name "b6"

pll v[1111];
ll f1[1111];
ll f2[1111];

const ll mod = 1e9 + 9999;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> v[i].X >> v[i].Y;

	sort(v + 1, v + n + 1, [&](pii x, pii y) {
		return x.Y < y.Y;
		});

	f1[0] = f2[0] = 1;
	FOR(i, 1, n)f1[i] = f1[i - 1] * (v[i].Y - v[i].X + 1) % mod;
	FOR(i, 1, n)f1[i] = f1[i - 1] * (v[i].Y - v[i].X) % mod;

	ll L = 0, R = 0;
	FOR(i, 1, n) {
		L = max(L, v[i].X);
		R = max(R, v[i].Y);
	}

	ll res = 0;
	FOR(mx, L, R) {
		int idx = n + 1;
		FOR(i, 1, n)if (v[i].Y >= mx) {
			idx = i;
			break;
		}

		ll sum1 = f1[idx - 1];
		FOR(i, idx, n) {
			sum1 *= mx - v[i].X + 1;
			sum1 %= mod;
		}
		res += sum1 * mx % mod;
	}
	FOR(mx, L, R) {
		int idx = n + 1;
		FOR(i, 1, n)if (v[i].Y >= mx) {
			idx = i;
			break;
		}

		ll sum2 = f2[idx - 1];
		FOR(i, idx, n) {
			sum2 *= mx - v[i].X;
			sum2 %= mod;
		}
		res -= sum2 * mx % mod;
	}
	cout << (res % mod + mod) % mod;
}