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
#define Name "KINHDOANH"

int n;
int a[(int)1e5 + 5];
int d[(int)1e5 + 5];

void compress() {
	map<int, int>mp;
	FOR(i, 1, n)mp[a[i]] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->Y = cnt++;
	}

	FOR(i, 1, n)d[i] = mp[a[i]];
}

ll bit[(int)1e5 + 5];

void update(int idx, ll v) {
	if (idx <= 0)return;
	for (idx; idx <= 1e5; idx += (idx & (-idx)))bit[idx] = max(bit[idx], v);
}

ll query(int idx) {
	ll res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res = max(res, bit[idx]);
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

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	compress();

	FOR(i, 1, n) {
		update(d[i], query(d[i] - 1) + a[i]);
	}

	cout << query(n);
}