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
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))

struct BIT {
	int bit[(int)3e5 + 5];

	void update(int idx, int v) {
		if (idx == 0)return;
		for (idx; idx <= 3e5; idx += (idx & (-idx)))bit[idx] += v;
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}
}v[3];

int getKey(int x) {
	if (x >= '0' && x <= '9')return 0;
	if (x >= 'a' && x <= 'z')return 1;
	return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	string s;

	cin >> n >> q >> s;
	s = "_" + s;

	FOR(i, 1, n) {
		v[getKey(s[i])].update(i, 1);
	}

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;

		if (t == 1) {
			v[getKey(s[x])].update(x, -1);
			v[getKey(s[y])].update(y, -1);
			swap(s[x], s[y]);
			v[getKey(s[x])].update(x, 1);
			v[getKey(s[y])].update(y, 1);
		}
		else {
			cout << ((min({ v[0].query(y) - v[0].query(x - 1),
			v[1].query(y) - v[1].query(x - 1),
		v[2].query(y) - v[2].query(x - 1) }) >= 1) && (y - x + 1) >= 6) << endl;
		}
	}
}
