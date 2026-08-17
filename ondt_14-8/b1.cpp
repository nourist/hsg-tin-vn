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

struct Node {
	int sum = 0, mn = 1e9;
	Node() {}
	Node(int x) {
		if (x == '(')sum = mn = 1;
		else sum = mn = -1;
	}
	Node(int _sum, int _mn) {
		sum = _sum;
		mn = _mn;
	}
}st[(int)2e5 + 5];

Node operator + (Node a, Node b) {
	return { a.sum + b.sum, min({a.mn, a.sum + b.mn}) };
}

int n, m;
string s;

void build() {
	FOR(i, 1, n)st[i + n - 1] = Node(s[i]);
	FOD(i, n - 1, 1)st[i] = st[i * 2] + st[i * 2 + 1];
}

void update(int idx, int ch) {
	for (st[idx += n - 1] = Node(ch); idx >= 2; idx /= 2)
		st[idx / 2] = st[idx / 2 * 2] + st[idx / 2 * 2 + 1];
}

bool query(int l, int r) {
	Node res1, res2;
	for (l += n - 1, r += n; l < r; l /= 2, r /= 2) {
		if (l & 1)res1 = res1 + st[l++];
		if (r & 1)res2 = st[--r] + res2;
	}
	res1 = res1 + res2;
	return res1.sum == 0 && res1.mn >= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m;
	cin >> s;
	s = "_" + s;

	build();

	FOR(i, 1, m) {
		int t, u, v;
		char ch;
		cin >> t >> u;
		if (t == 0) {
			cin >> ch;
			update(u, ch);
		}
		else {
			cin >> v;
			cout << query(u, v);
		}
	}
}
