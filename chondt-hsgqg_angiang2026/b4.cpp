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

const int C[6][6] = {
	{1, 0, 0, 0, 0, 0}, // k = 0
	{1, 1, 0, 0, 0, 0}, // k = 1
	{1, 2, 1, 0, 0, 0}, // k = 2
	{1, 3, 3, 1, 0, 0}, // k = 3
	{1, 4, 6, 4, 1, 0}, // k = 4
	{1, 5, 10, 10, 5, 1}  // k = 5
};

const ll mod = 1e9 + 7;

struct Fenwick {
	ll bit[(int)2e5 + 5];

	void update(int idx, ll v) {
		if (idx == 0)return;
		for (idx; idx <= 2e5; idx += (idx & (-idx)))bit[idx] = (bit[idx] + v) % mod;
	}

	ll query(int idx) {
		ll res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res = (res + bit[idx]) % mod;
		return res;
	}
}fw[6];

ll powll(ll x, ll n) {
	ll res = 1;
	FOR(i, 1, n)res = res * x % mod;
	return res;
}

ll a[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n) {
		FOR(k, 0, 5) {
			fw[k].update(i, powll(a[i], k));
		}
	}

	while (q--) {
		int t, u, v, k;
		cin >> t >> u >> v;
		if (t == 1) {
			FOR(h, 0, 5) {
				fw[h].update(u, (powll(v, h) - powll(a[u], h) + mod) % mod);
			}
			a[u] = v;
		}
		else {
			cin >> k;
			ll res = 0;
			FOR(h, 0, k) {
				res += C[k][h] * (fw[h].query(v) - fw[h].query(u - 1) + mod) % mod * (fw[k - h].query(v) - fw[k - h].query(u - 1) + mod) % mod;
			}
			cout << res % mod << endl;
		}
	}
}
