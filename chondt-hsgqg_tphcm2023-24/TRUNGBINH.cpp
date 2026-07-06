#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "trungbinh"

ll a[(int)1e6 + 6];
ll f[(int)1e6 + 6];
int bit[(int)1e6 + 6];

void update(int idx) {
	for (idx; idx <= 1e6; idx += (idx & (-idx)))bit[idx]++;
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, g;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	cin >> g;

	FOR(i, 1, n)a[i] -= g;
	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	map<ll, int>mp;
	FOR(i, 0, n)mp[f[i]] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->Y = cnt++;

	ll res = 0;
	update(mp[0]);
	FOR(i, 1, n) {
		res += query(mp[f[i]]);
		update(mp[f[i]]);
	}
	cout << res;
}