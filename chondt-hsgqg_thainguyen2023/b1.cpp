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

int n, q;
int a[(int)2e5 + 5];
int b[(int)2e5 + 5];
int f[(int)2e5 + 5];
vi freq[(int)2e5 + 5];

struct SegmentTree {
	ll st[(int)4e5 + 5];
	int* arr;

	SegmentTree(int _arr[]) : arr(_arr) {}

	void build() {
		FOR(i, 1, n)st[i + n - 1] = arr[i];
		FOD(i, n - 1, 1)st[i] = st[i * 2 + 1] + st[i * 2];
	}

	void update(int idx, int val) {
		for (st[idx += n - 1] = val; idx > 1; idx /= 2) {
			st[idx / 2] = st[idx] + st[idx ^ 1];
		}
	}

	ll query(int l, int r) {
		ll res = 0;
		for (l += n - 1, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1)res += st[l++];
			if (r & 1)res += st[--r];
		}
		return res;
	}
}st1(a), st2(b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	for (int i = 1; i <= 2e5; i += 2)for (int j = i; j <= 2e5; j += i)f[j] = i;

	cin >> n >> q;
	FOR(i, 1, n)freq[f[i]].pb(i);

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)b[i] = a[f[i]];

	st1.build();
	st2.build();

	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1) {
			st1.update(u, v);
			for (int j : freq[u]) {
				st2.update(j, v);
			}
		}
		else {
			cout << st1.query(u, v) + st2.query(u, v) << endl;
		}
	}
}
