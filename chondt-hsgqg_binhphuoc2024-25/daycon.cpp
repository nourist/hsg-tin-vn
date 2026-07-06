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
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "daycon"

int n;
struct Line {
	int l, r, id, res;
}v[(int)2e5 + 5];

void compress() {
	map<int, int>mp;
	FOR(i, 1, n)mp[v[i].l] = 1;
	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->Y = cnt++;
	FOR(i, 1, n) {
		v[i].l = mp[v[i].l];
		// v[i].r = mp[v[i].r];
	}
}

int bit[(int)2e5 + 5];

void update(int idx, int v) {
	if (idx == 0)return;
	for (idx; idx <= 2e5; idx += (idx & (-idx)))bit[idx] = max(bit[idx], v);
}

int query(int idx) {
	int res = 0;
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

	FOR(i, 1, n) {
		int a, t;
		cin >> a >> t;

		v[i] = { a,a + t,i };
	}

	compress();

	sort(v + 1, v + n + 1, [&](Line a, Line b) {
		return a.r <= b.r;
		});

	FOD(i, n, 1) {
		v[i].res = query(v[i].l);
		update(v[i].l, v[i].res + 1);
	}


	sort(v + 1, v + n + 1, [&](Line a, Line b) {
		return a.id < b.id;
		});

	FOR(i, 1, n)cout << v[i].res << ' ';
}
