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

int mu[65];

void prebuild_mu() {
	for (int i = 1; i <= 64; ++i) {
		if (i == 1) {
			mu[i] = 1;
			continue;
		}
		int temp = i, count = 0;
		bool square_free = true;
		for (int p = 2; p * p <= temp; ++p) {
			if (temp % p == 0) {
				temp /= p;
				count++;
				if (temp % p == 0) {
					square_free = false;
					break;
				}
			}
		}
		if (temp > 1) count++;

		if (!square_free) mu[i] = 0;
		else mu[i] = (count % 2 == 0) ? 1 : -1;
	}
}

ll power_limit(ll a, int k, ll n) {
	__int128 res = 1;

	FOR(i, 1, k) {
		res *= a;
		if (res > n) return n + 1;
	}

	return (ll)res;
}

ll kth_root(ll n, int k) {
	if (k == 1) return n;

	ll l = 1, r = min(n, (ll)2e9);

	while (l < r) {
		ll mid = (l + r + 1) / 2;

		if (power_limit(mid, k, n) <= n)
			l = mid;
		else
			r = mid - 1;
	}

	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	prebuild_mu();

	ll q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		ll res = 0;
		FOR(i, 1, 64) {
			res += (kth_root(n, i) - 1) * mu[i];
		}
		cout << res << endl;
	}
}