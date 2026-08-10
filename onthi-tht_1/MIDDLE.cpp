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
#define Name "MIDDLE"

int n, b, a[(int)1e5 + 5];
int f[(int)1e5 + 5];

struct Fenwick {
	int bit[(int)2e5 + 5];

	void clear() {
		memset(bit, 0, sizeof bit);
	}

	void update(int idx) {
		for (idx += 1e5 + 1; idx <= 2e5 + 2; idx += (idx & (-idx)))bit[idx]++;
	}

	int query(int idx) {
		int res = 0;
		for (idx += 1e5 + 1; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}
}odd, even;

ll cnt(ll x) {
	memset(f, 0, sizeof f);
	odd.clear();
	even.clear();

	FOR(i, 1, n)f[i] = f[i - 1] + (a[i] >= x ? 1 : -1);

	even.update(f[0]);

	ll res = 0;
	FOR(i, 1, n) {
		if (i % 2) {
			res += even.query(f[i] - 1);
			odd.update(f[i]);
		}
		else {
			res += odd.query(f[i] - 1);
			even.update(f[i]);
		}
	}
	return res;
}

/*
f[i] - f[j-1] >= 1
f[j-1] <= f[i] - 1
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> b;
	FOR(i, 1, n)cin >> a[i];

	cout << cnt(b) - cnt(b + 1);
}
